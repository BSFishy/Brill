
#include "literal_expression.h"

#include "literal_literal_expression.h"
#include "lang/ast/literal/literal.h"
#include "lang/ast/abstract/convert_context.h"

#include "util.h"

using namespace Brill::AST;

LiteralExpression::LiteralExpression(const std::shared_ptr<SymbolTable> &st) : PrimaryExpression(st) {}

std::shared_ptr<LiteralExpression> Brill::AST::convert(const std::shared_ptr<ConvertContext> &cctx, BrillParser::LiteralExpressionContext *ctx) {
    if (BrillParser::LiteralContext *literalContext = ctx->literal()) {
        return std::make_shared<LiteralLiteralExpression>(cctx->parent->getSymbolTable(), convert(cctx, literalContext));
    } else {
        throw NotImplementedException();
    }
}
