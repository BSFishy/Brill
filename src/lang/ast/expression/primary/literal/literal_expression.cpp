
#include "literal_expression.h"

#include "literal_literal_expression.h"
#include "lang/ast/literal/literal.h"
#include "lang/ast/abstract/convert_context.h"

#include "util.h"

using namespace Brill::AST;

LiteralExpression::LiteralExpression(const std::shared_ptr<SymbolTable> &st) : PrimaryExpression(st) {}

std::shared_ptr<LiteralExpression> Brill::AST::convert(const std::shared_ptr<ConvertContext> &cctx, BrillParser::LiteralExpressionContext *ctx) {
    if (BrillParser::LiteralContext *literalContext = ctx->literal()) {
        std::shared_ptr<Literal> literal = convert(cctx, literalContext);
        if (!literal) {
            return nullptr;
        }

        return std::make_shared<LiteralLiteralExpression>(cctx->parent->getSymbolTable(), literal);
    } else {
        cctx->error(ctx->getStart(), "Not implemented");
        return nullptr;
    }
}
