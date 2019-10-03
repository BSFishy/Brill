
#pragma once

#include <memory>

#include "llvm/IR/Value.h"

#include "statement.h"
#include "tree/expression/expression.h"

namespace Brill::IR {
    class ExpressionStatement : public Statement {
    public:
        std::shared_ptr<Expression> expression;

        explicit ExpressionStatement(std::shared_ptr<Expression> e) : expression(std::move(e)) {}

        llvm::Value *codegen(std::shared_ptr<CodegenContext>) override;
    };
}
