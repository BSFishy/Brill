
#pragma once

#include <memory>

#include "BrillParser.h"

#include "tree/abstract/codegen/codegen_context.h"
#include "tree/expression/prefix_expression.h"

namespace Brill::IR::Convert {
    std::shared_ptr<PrefixExpression> convert(BrillParser::PrefixExpressionContext *);
}
