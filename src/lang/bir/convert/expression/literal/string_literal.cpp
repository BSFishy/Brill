
#include "string_literal.h"

using namespace Brill::IR;

std::shared_ptr<StringLiteral> Convert::convertStringLiteral(antlr4::tree::TerminalNode *node) {
    return std::make_shared<StringLiteral>(node->getText());
}
