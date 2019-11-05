
#include "literal.h"

#include "string_literal.h"
#include "lang/ast/abstract/convert_context.h"

#include "util.h"

using namespace Brill::AST;

Literal::Literal(const std::shared_ptr<SymbolTable> &st) : Node(st) {}

std::shared_ptr<Literal> Brill::AST::convert(const std::shared_ptr<ConvertContext> &cctx, BrillParser::LiteralContext *ctx) {
    if (antlr4::tree::TerminalNode *stringValue = ctx->StringLiteral()) {
        return std::make_shared<StringLiteral>(cctx->parent->getSymbolTable(), stringValue->getText());
    } else {
        throw NotImplementedException();
    }
}
