
#include "prefix_expression.h"

#include "util.h"

#include "postfix/postfix_expression.h"

using namespace Brill::IR;

std::shared_ptr<PrefixExpression> Convert::convert(BrillParser::PrefixExpressionContext *ctx) {
    std::shared_ptr<PostfixExpression> postfixExpression = convert(ctx->postfixExpression());
    std::shared_ptr<PrefixExpression> prefixExpression(new PrefixExpression(postfixExpression));

    return prefixExpression;
}
