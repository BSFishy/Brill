
#include "primary_expression.h"

#include "lang/ast/abstract/convert_context.h"
#include "literal/literal_expression.h"

#include "primary_identifier_expression.h"

#include "util.h"

using namespace Brill::AST;

PrimaryExpression::PrimaryExpression(const std::shared_ptr<SymbolTable> &st) : Node(st) {}

std::shared_ptr<PrimaryExpression> Brill::AST::convert(const std::shared_ptr<ConvertContext> &cctx, BrillParser::PrimaryExpressionContext *ctx) {
    if (BrillParser::LiteralExpressionContext *literalContext = ctx->literalExpression()) {
        return convert(cctx, literalContext);
    } else if (antlr4::tree::TerminalNode *identifier = ctx->Identifier()) {
        return std::make_shared<PrimaryIdentifierExpression>(cctx->parent->getSymbolTable(), identifier->getText());
    } else {
        throw NotImplementedException();
    }
}
