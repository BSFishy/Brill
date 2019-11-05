
#pragma once

#include <string>

#include "primary_expression.h"

namespace Brill::AST {
    class NamedNode;

    class PrimaryIdentifierExpression : public PrimaryExpression {
        std::shared_ptr<NamedNode> lookup(std::string) const;
        std::string identifier;
    public:
        PrimaryIdentifierExpression(const std::shared_ptr<SymbolTable>&, std::string);
        // explicit PrimaryIdentifierExpression(const std::shared_ptr<SymbolTable> &st, std::string i) : PrimaryExpression(st), identifier(std::move(i)) {}

        llvm::Value *codegen(std::shared_ptr<CodegenContext>) const override;
    };
}
