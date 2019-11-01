
#pragma once

#include <memory>

#include "postfix_expression.h"

namespace Brill::AST {
    class PrimaryExpression;

    class PostfixPrimaryExpression : public PostfixExpression {
    public:
        std::shared_ptr<PrimaryExpression> primaryExpression;

        explicit PostfixPrimaryExpression(const std::shared_ptr<PrimaryExpression> &pe) {
            primaryExpression = pe;
        }

        llvm::Value *codegen(std::shared_ptr<CodegenContext>) override;
    };

    std::shared_ptr<PostfixPrimaryExpression> convert(const std::shared_ptr<ConvertContext>&, BrillParser::PostfixPrimaryExpressionContext*);
}
