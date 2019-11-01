
#pragma once

#include "statement.h"

#include "lang/ast/expression/expression.h"

namespace Brill::AST {
    class ExpressionStatement : public Statement {
    public:
        std::shared_ptr<Expression> expression;

        explicit ExpressionStatement(const std::shared_ptr<Expression> &e) {
            expression = e;
        }

        llvm::Value *codegen(std::shared_ptr<CodegenContext>) override;
    };
}
