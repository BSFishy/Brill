
#include "literal_expression.h"

#include "convert/expression/literal/literal.h"

#include "tree/expression/primary/literal_literal_expression.h"

#include "util.h"

using namespace Brill::IR;

std::shared_ptr<LiteralExpression> Convert::convert(BrillParser::LiteralExpressionContext *ctx) {
    if (BrillParser::LiteralContext *literalContext = ctx->literal()) {
        std::shared_ptr<Literal> literal = convert(literalContext);
        return std::make_shared<LiteralLiteralExpression>(literal);
    } else {
        throw NotImplementedException();
    }
}
