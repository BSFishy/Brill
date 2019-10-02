
#pragma once

#include <memory>

#include "BrillParser.h"

#include "tree/abstract/codegen/codegen_context.h"

namespace Brill::IR::Convert {
    std::shared_ptr<CodegenContext> convert(std::shared_ptr<CodegenContext>, BrillParser::FunctionDeclarationContext *);
}
