
#include "identifier_expression.h"

#include <memory>

using namespace Brill::IR;

std::shared_ptr<IdentifierExpression> Convert::convertIdentifier(antlr4::tree::TerminalNode *node) {
    return std::make_shared<IdentifierExpression>(node->getText());
}
