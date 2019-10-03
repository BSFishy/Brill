
#include "literal.h"

#include "string_literal.h"

#include "util.h"

using namespace Brill::IR;

std::shared_ptr<Literal> Convert::convert(BrillParser::LiteralContext *ctx) {
    if (antlr4::tree::TerminalNode *stringNode = ctx->StringLiteral()) {
        return convertStringLiteral(stringNode);
    } else {
        throw NotImplementedException();
    }
}
