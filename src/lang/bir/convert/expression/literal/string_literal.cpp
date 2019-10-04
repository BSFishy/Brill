
#include "string_literal.h"

using namespace Brill::IR;

std::shared_ptr<StringLiteral> Convert::convertStringLiteral(antlr4::tree::TerminalNode *node) {
    std::string val = node->getText();
    return std::make_shared<StringLiteral>(val.substr(1, val.length()-2));
}
