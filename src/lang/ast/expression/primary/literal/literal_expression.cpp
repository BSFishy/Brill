
#include "literal_expression.h"

#include "literal_literal_expression.h"
#include "lang/ast/literal/literal.h"

#include "util.h"

using namespace Brill::AST;

std::shared_ptr<LiteralExpression> Brill::AST::convert(std::shared_ptr<ConvertContext> cctx, BrillParser::LiteralExpressionContext *ctx) {
    if (BrillParser::LiteralContext *literalContext = ctx->literal()) {
        return std::make_shared<LiteralLiteralExpression>(convert(cctx, literalContext));
    } else {
        throw NotImplementedException();
    }
}
