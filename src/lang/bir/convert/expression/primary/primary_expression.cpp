
#include "primary_expression.h"

#include "identifier_expression.h"
#include "literal_expression.h"

#include "util.h"

using namespace Brill::IR;

std::shared_ptr<PrimaryExpression> Convert::convert(BrillParser::PrimaryExpressionContext *ctx) {
    if (antlr4::tree::TerminalNode *identifierNode = ctx->Identifier()) {
        return convertIdentifier(identifierNode);
    } else if (BrillParser::LiteralExpressionContext *literalContext = ctx->literalExpression()) {
        return convert(literalContext);
    } else {
        printf("not implemented: %s\n", ctx->getText().c_str());
        throw NotImplementedException();
    }
}
