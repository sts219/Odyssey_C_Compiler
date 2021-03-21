#include "ast/operators/binaryOps/ast_binaryLShift.hpp"

void BinaryLShift::PrettyPrint(std::ostream &dst, std::string indent) const
{
  dst << indent << "Binary Left Shift [ " << std::endl;
  dst << indent << "Left Op:" << std::endl;
  LeftOp()->PrettyPrint(dst, indent+"  ");
  std::cout << indent << "Right Op: " << std::endl;
  RightOp()->PrettyPrint(dst, indent+"  ");
  std::cout << indent << "]" <<std::endl;
}

void BinaryLShift::generateMIPS(std::ostream &dst, Context &context, int destReg) const
{
  int regRight;
  if( ((regRight = context.regFile.allocate()) == -1) ){
    std::cerr << "OOPSIES NO REGS ARE FREE. OVERWRITING" << std::endl;
  }

  LeftOp()->generateMIPS(dst, context, destReg);
  RightOp()->generateMIPS(dst, context, regRight);

  EZPrint(dst, "sllv", destReg, destReg, regRight);

  context.regFile.freeReg(regRight);
}
 
