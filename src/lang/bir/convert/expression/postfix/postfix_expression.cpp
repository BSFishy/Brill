
#include "postfix_expression.h"

#include <string>
#include <iostream>

#include "function_call_expression.h"
#include "convert/expression/primary/primary_expression.h"
#include "tree/expression/postfix/postfix_primary_expression.h"

#include "util.h"

using namespace Brill::IR;

std::shared_ptr<PostfixExpression> Convert::convert(BrillParser::PostfixExpressionContext *ctx) {
    BrillParser::PrimaryExpressionContext *primaryExpressionContext = ctx->postfixBaseExpression()->primaryExpression();
    std::shared_ptr<PrimaryExpression> primaryExpression = convert(primaryExpressionContext);

    if (BrillParser::PostfixFunctionExpressionContext *functionContext = ctx->postfixFunctionExpression()) {
        return convert(primaryExpression, functionContext);
    } else if (BrillParser::PostfixPostExpressionContext *postExpressionContext = ctx->postfixPostExpression()) {
        throw NotImplementedException();
    } else {
        return std::make_shared<PostfixPrimaryExpression>(primaryExpression);
    }
}
