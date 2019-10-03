
#pragma once

#include <memory>

#include "BrillParser.h"

#include "tree/abstract/codegen/codegen_context.h"
#include "tree/expression/primary/literal_expression.h"

namespace Brill::IR::Convert {
    std::shared_ptr<LiteralExpression> convert(BrillParser::LiteralExpressionContext *);
}
