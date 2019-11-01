
#include "primary_expression.h"

#include "literal/literal_expression.h"

#include "primary_identifier_expression.h"

#include "util.h"

using namespace Brill::AST;

std::shared_ptr<PrimaryExpression> Brill::AST::convert(const std::shared_ptr<ConvertContext> &cctx, BrillParser::PrimaryExpressionContext *ctx) {
    if (BrillParser::LiteralExpressionContext *literalContext = ctx->literalExpression()) {
        return convert(cctx, literalContext);
    } else if (antlr4::tree::TerminalNode *identifier = ctx->Identifier()) {
        return std::make_shared<PrimaryIdentifierExpression>(identifier->getText());
    } else {
        throw NotImplementedException();
    }
}
