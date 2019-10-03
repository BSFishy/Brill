
#pragma once

#include <memory>

#include "BrillParser.h"

#include "tree/abstract/codegen/codegen_context.h"
#include "tree/expression/expression.h"

namespace Brill::IR::Convert {
    std::shared_ptr<Expression> convert(BrillParser::ExpressionContext *);
}
