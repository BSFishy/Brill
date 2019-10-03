
#pragma once

#include <memory>

#include "llvm/IR/Value.h"

#include "primary_expression.h"

namespace Brill::IR {
    class LiteralExpression : public PrimaryExpression {
    public:
        llvm::Value *codegen(std::shared_ptr<CodegenContext>) override = 0;
    };
}
