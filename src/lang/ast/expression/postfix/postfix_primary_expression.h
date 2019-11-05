
#pragma once

#include <memory>

#include "postfix_expression.h"

namespace Brill::AST {
    class PrimaryExpression;

    class PostfixPrimaryExpression : public PostfixExpression {
        std::shared_ptr<PrimaryExpression> primaryExpression;
    public:
        PostfixPrimaryExpression(const std::shared_ptr<SymbolTable>&, const std::shared_ptr<PrimaryExpression>&);
        // explicit PostfixPrimaryExpression(const std::shared_ptr<SymbolTable> &st, const std::shared_ptr<PrimaryExpression> &pe) : PostfixExpression(st) {
        //     primaryExpression = pe;
        // }

        llvm::Value *codegen(std::shared_ptr<CodegenContext>) const override;
    };

    std::shared_ptr<PostfixPrimaryExpression> convert(const std::shared_ptr<ConvertContext>&, BrillParser::PostfixPrimaryExpressionContext*);
}
