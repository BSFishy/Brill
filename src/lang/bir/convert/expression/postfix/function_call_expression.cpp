
#include "function_call_expression.h"
#include "convert/expression/expression.h"
#include "tree/expression/postfix/function_call_expression.h"

#include <iostream>

using namespace Brill::IR;

std::shared_ptr<FunctionCallExpression> Convert::convert(std::shared_ptr<PrimaryExpression> identifier, BrillParser::PostfixFunctionExpressionContext *ctx) {
    std::shared_ptr<FunctionCallExpression> functionCall = std::make_shared<FunctionCallExpression>(identifier);

    if (BrillParser::FunctionCallArgumentListContext *argumentList = ctx->functionCallArgumentClause()->functionCallArgumentList()) {
        for (BrillParser::FunctionCallArgumentContext* const& argumentContext : argumentList->functionCallArgument()) {
            functionCall->arguments.push_back(convert(argumentContext->expression()));
        }
    }

    return functionCall;
}
