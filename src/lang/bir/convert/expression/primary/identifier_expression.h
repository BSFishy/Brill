
#pragma once

#include <memory>

#include "BrillParser.h"

#include "tree/abstract/codegen/codegen_context.h"
#include "tree/expression/primary/identifier_expression.h"

namespace Brill::IR::Convert {
    std::shared_ptr<IdentifierExpression> convertIdentifier(antlr4::tree::TerminalNode *);
}
