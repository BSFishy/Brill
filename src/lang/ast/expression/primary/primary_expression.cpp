
#include "primary_expression.h"

#include "literal/literal_expression.h"

#include "util.h"

using namespace Brill::AST;

std::shared_ptr<PrimaryExpression> Brill::AST::convert(const std::shared_ptr<ConvertContext> &cctx, BrillParser::PrimaryExpressionContext *ctx) {
    if (BrillParser::LiteralExpressionContext *literalContext = ctx->literalExpression()) {
        return convert(cctx, literalContext);
    } else {
        throw NotImplementedException();
    }
}
