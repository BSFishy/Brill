
#pragma once

#include <string>

#include "primary_expression.h"

namespace Brill::AST {
    class PrimaryIdentifierExpression : public PrimaryExpression {
        std::shared_ptr<NamedNode> lookup(std::string);
    public:
        std::string identifier;

        explicit PrimaryIdentifierExpression(const std::shared_ptr<SymbolTable> &st, std::string i) : PrimaryExpression(st), identifier(std::move(i)) {}

        llvm::Value *codegen(std::shared_ptr<CodegenContext>) override;
    };
}
