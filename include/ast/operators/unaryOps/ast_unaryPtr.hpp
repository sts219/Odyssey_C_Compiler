#ifndef ast_unaryPtr_hpp
#define ast_unaryPtr_hpp

#include "ast/operators/ast_unaryOperation.hpp"

class UnaryPtr
    : public UnaryOperation
{
public:

    using UnaryOperation::UnaryOperation;

    virtual void PrettyPrint(std::ostream &dst, std::string indent) const override;


};

#endif

