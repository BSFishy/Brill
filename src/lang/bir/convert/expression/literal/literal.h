
#pragma once

#include <memory>

#include "BrillParser.h"

#include "tree/abstract/codegen/codegen_context.h"
#include "tree/expression/literal/literal.h"

namespace Brill::IR::Convert {
    std::shared_ptr<Literal> convert(BrillParser::LiteralContext *);
}
