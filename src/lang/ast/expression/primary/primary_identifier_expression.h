
#pragma once

#include <string>

#include "primary_expression.h"

namespace Brill::AST {
    class PrimaryIdentifierExpression : public PrimaryExpression {
        std::shared_ptr<NamedNode> lookup(std::string);
    public:
        std::string identifier;

        explicit PrimaryIdentifierExpression(std::string i) : identifier(std::move(i)) {}

        llvm::Value *codegen(std::shared_ptr<CodegenContext>) override;
    };
}
