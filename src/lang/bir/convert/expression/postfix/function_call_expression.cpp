
#include "function_call_expression.h"
#include "convert/expression/expression.h"
#include "tree/expression/postfix/function_call_expression.h"

#include <iostream>

using namespace Brill::IR;

std::shared_ptr<FunctionCallExpression> Convert::convert(BrillParser::PostfixBaseExpressionContext *baseCtx, BrillParser::PostfixFunctionExpressionContext *ctx) {
    std::shared_ptr<FunctionCallExpression> functionCall(new FunctionCallExpression(baseCtx->getText()));

    if (BrillParser::FunctionCallArgumentListContext *argumentList = ctx->functionCallArgumentClause()->functionCallArgumentList()) {
        for (BrillParser::FunctionCallArgumentContext* const& argumentContext : argumentList->functionCallArgument()) {
            functionCall->arguments.push_back(convert(argumentContext->expression()));
        }
    }

    return functionCall;
}
