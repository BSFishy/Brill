
#pragma once

#include <memory>

#include "BrillParser.h"

#include "tree/abstract/codegen/codegen_context.h"

namespace Brill {
    std::shared_ptr<IR::CodegenContext> convert(BrillParser::TopLevelContext *);
}
