
#pragma once

#include <string>

#include "primary_expression.h"

namespace Brill::AST {
    class NamedNode;

    class PrimaryIdentifierExpression : public PrimaryExpression {
        std::string identifier;
    public:
        PrimaryIdentifierExpression(const std::shared_ptr<SymbolTable>&, std::string);

        llvm::Value *codegen(std::shared_ptr<CodegenContext>) const override;
    };
}
