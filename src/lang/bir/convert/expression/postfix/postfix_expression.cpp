
#include "postfix_expression.h"

#include <string>
#include <iostream>

#include "function_call_expression.h"

#include "util.h"

using namespace Brill::IR;

std::shared_ptr<PostfixExpression> Convert::convert(BrillParser::PostfixExpressionContext *ctx) {
    std::string name = ctx->postfixBaseExpression()->getText();

    if (BrillParser::PostfixFunctionExpressionContext *functionContext = ctx->postfixFunctionExpression()) {
        return convert(ctx->postfixBaseExpression(), functionContext);
    } else {
        throw NotImplementedException();
    }
}
