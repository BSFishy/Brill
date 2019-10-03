
#pragma once

#include <string>
#include <utility>

#include "llvm/IR/Value.h"

#include "primary_expression.h"

namespace Brill::IR {
    class IdentifierExpression : public PrimaryExpression {
    public:
        std::string value;

        explicit IdentifierExpression(std::string v) : value(std::move(v)) {}

        llvm::Value *codegen(std::shared_ptr<CodegenContext>) override;
    };
}
