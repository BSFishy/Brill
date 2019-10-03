
#pragma once

#include <memory>

#include "BrillParser.h"

#include "tree/abstract/codegen/codegen_context.h"
#include "tree/expression/postfix/function_call_expression.h"
#include "tree/expression/primary/primary_expression.h"

namespace Brill::IR::Convert {
    std::shared_ptr<FunctionCallExpression> convert(std::shared_ptr<PrimaryExpression>, BrillParser::PostfixFunctionExpressionContext *);
}
