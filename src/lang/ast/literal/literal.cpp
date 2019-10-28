
#include "literal.h"

#include "string_literal.h"

#include "util.h"

using namespace Brill::AST;

std::shared_ptr<Literal> Brill::AST::convert(std::shared_ptr<ConvertContext> cctx, BrillParser::LiteralContext *ctx) {
    if (antlr4::tree::TerminalNode *stringValue = ctx->StringLiteral()) {
        return std::make_shared<StringLiteral>(stringValue->getText());
    } else {
        throw NotImplementedException();
    }
}
