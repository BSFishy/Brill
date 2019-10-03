
#include "function_call_expression.h"

#include <iostream>

using namespace Brill::IR;

std::shared_ptr<FunctionCallExpression> Convert::convert(BrillParser::PostfixBaseExpressionContext *baseCtx, BrillParser::PostfixFunctionExpressionContext *ctx) {
    printf("base: %s\nfunction: %s\n", baseCtx->getText().c_str(), ctx->functionCallArgumentClause()->functionCallArgumentList()->getText().c_str());
}
