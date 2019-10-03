
#include "expression.h"

#include "util.h"

#include "prefix_expression.h"

using namespace Brill::IR;

std::shared_ptr<Expression> Convert::convert(BrillParser::ExpressionContext *ctx) {
    std::shared_ptr<PrefixExpression> prefixExpression = convert(ctx->prefixExpression());
    std::shared_ptr<Expression> expression(new Expression(prefixExpression));

    return expression;
}
