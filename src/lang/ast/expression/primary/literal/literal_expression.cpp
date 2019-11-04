
#include "literal_expression.h"

#include "literal_literal_expression.h"
#include "lang/ast/literal/literal.h"

#include "util.h"

using namespace Brill::AST;

std::shared_ptr<LiteralExpression> Brill::AST::convert(const std::shared_ptr<ConvertContext> &cctx, BrillParser::LiteralExpressionContext *ctx) {
    if (BrillParser::LiteralContext *literalContext = ctx->literal()) {
        return std::make_shared<LiteralLiteralExpression>(cctx->parent->symbolTable, convert(cctx, literalContext));
    } else {
        throw NotImplementedException();
    }
}
