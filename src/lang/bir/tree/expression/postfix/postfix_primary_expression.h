
#pragma once

#include <memory>

#include "postfix_expression.h"
#include "tree/expression/primary/primary_expression.h"

namespace Brill::IR {
    class PostfixPrimaryExpression : public PostfixExpression {
    public:
        std::shared_ptr<PrimaryExpression> primaryExpression;
        
        explicit PostfixPrimaryExpression(std::shared_ptr<PrimaryExpression> &e) : primaryExpression(e) {}

        llvm::Value *codegen(std::shared_ptr<CodegenContext>) override;
    };
}
