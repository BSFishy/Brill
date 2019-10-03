
#pragma once

#include <memory>

#include "BrillParser.h"

#include "tree/abstract/codegen/codegen_context.h"
#include "tree/expression/postfix/function_call_expression.h"

namespace Brill::IR::Convert {
    std::shared_ptr<FunctionCallExpression> convert(BrillParser::PostfixBaseExpressionContext *, BrillParser::PostfixFunctionExpressionContext *);
}
