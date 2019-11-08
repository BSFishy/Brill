
#pragma once

#include "statement.h"

#include "lang/ast/expression/expression.h"

namespace Brill::AST {
    class ExpressionStatement : public Statement {
        std::shared_ptr<Expression> expression;
    public:
        ExpressionStatement(const std::shared_ptr<SymbolTable>&, const std::shared_ptr<Expression>&);

        llvm::Value *codegen(std::shared_ptr<CodegenContext>) const override;
    };
}
