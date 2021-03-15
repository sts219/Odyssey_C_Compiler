#include "ast/operators/binaryOps/ast_binarySub.hpp"

void BinarySub::PrettyPrint(std::ostream &dst, std::string indent) const
{
  dst << indent << "Binary Subtraction [ " << std::endl;
  dst << indent << "Left Op:" << std::endl;
  LeftOp()->PrettyPrint(dst, indent+"  ");
  std::cout << indent << "Right Op: " << std::endl;
  RightOp()->PrettyPrint(dst, indent+"  ");
  std::cout << indent << "]" <<std::endl;
}