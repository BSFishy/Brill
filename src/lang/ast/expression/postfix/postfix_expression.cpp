
#include "postfix_expression.h"

#include "function_call_expression.h"
#include "postfix_primary_expression.h"

#include "util.h"

using namespace Brill::AST;

std::shared_ptr<PostfixExpression> Brill::AST::convert(const std::shared_ptr<ConvertContext> &cctx, BrillParser::PostfixExpressionContext *ctx) {
    if (BrillParser::FunctionCallExpressionContext *callContext = dynamic_cast<BrillParser::FunctionCallExpressionContext*>(ctx)) {
        return convert(cctx, callContext);
    } else if (BrillParser::PostfixPrimaryExpressionContext *primaryContext = dynamic_cast<BrillParser::PostfixPrimaryExpressionContext*>(ctx)) {
        return convert(cctx, primaryContext);
    } else {
        throw NotImplementedException();
    }
}
