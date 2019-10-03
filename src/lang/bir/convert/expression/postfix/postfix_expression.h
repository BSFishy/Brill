
#pragma once

#include <memory>

#include "BrillParser.h"

#include "tree/abstract/codegen/codegen_context.h"
#include "tree/expression/postfix/postfix_expression.h"

namespace Brill::IR::Convert {
    std::shared_ptr<PostfixExpression> convert(BrillParser::PostfixExpressionContext *);
}
