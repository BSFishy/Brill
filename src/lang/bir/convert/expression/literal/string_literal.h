
#pragma once

#include <memory>

#include "BrillParser.h"

#include "tree/abstract/codegen/codegen_context.h"
#include "tree/expression/literal/string_literal.h"

namespace Brill::IR::Convert {
    std::shared_ptr<StringLiteral> convertStringLiteral(antlr4::tree::TerminalNode *);
}
