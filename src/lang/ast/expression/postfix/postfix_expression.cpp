
#include "postfix_expression.h"

#include "lang/ast/abstract/convert_context.h"
#include "function_call_expression.h"
#include "postfix_primary_expression.h"

#include "util.h"

using namespace Brill::AST;

PostfixExpression::PostfixExpression(const std::shared_ptr<SymbolTable> &st) : Node(st) {}

std::shared_ptr<PostfixExpression> Brill::AST::convert(const std::shared_ptr<ConvertContext> &cctx, BrillParser::PostfixExpressionContext *ctx) {
    if (BrillParser::FunctionCallExpressionContext *callContext = dynamic_cast<BrillParser::FunctionCallExpressionContext*>(ctx)) {
        return convert(cctx, callContext);
    } else if (BrillParser::PostfixPrimaryExpressionContext *primaryContext = dynamic_cast<BrillParser::PostfixPrimaryExpressionContext*>(ctx)) {
        return convert(cctx, primaryContext);
    } else {
        cctx->error(ctx->getStart(), "Not implemented");
        return nullptr;
    }
}
