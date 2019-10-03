
#pragma once

#include <string>
#include <list>
#include <memory>

#include "llvm/IR/Value.h"

#include "tree/expression/expression.h"
#include "postfix_expression.h"
#include "tree/expression/primary/primary_expression.h"

namespace Brill::IR {
    class FunctionCallExpression : public PostfixExpression {
    public:
        std::shared_ptr<PrimaryExpression> identifier;
        std::list<std::shared_ptr<Expression>> arguments;

        explicit FunctionCallExpression(std::shared_ptr<PrimaryExpression> &i) : identifier(i), arguments() {}

        llvm::Value *codegen(std::shared_ptr<CodegenContext>) override;
    };
}
