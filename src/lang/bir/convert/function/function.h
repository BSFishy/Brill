
#pragma once

#include <memory>

#include "BrillParser.h"

#include "tree/abstract/codegen/codegen_context.h"
#include "tree/function/function.h"

namespace Brill::IR::Convert {
    std::shared_ptr<Function> convert(BrillParser::FunctionDeclarationContext *);
}
