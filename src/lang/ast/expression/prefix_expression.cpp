
#include "prefix_expression.h"

using namespace Brill::AST;

llvm::Value *PrefixExpression::codegen(std::shared_ptr<CodegenContext> ctx) {
    return this->postfixExpression->codegen(ctx);
}

std::shared_ptr<PrefixExpression> Brill::AST::convert(const std::shared_ptr<ConvertContext> &cctx, BrillParser::PrefixExpressionContext *ctx) {
    std::shared_ptr<PostfixExpression> postfixExpression = convert(cctx, ctx->postfixExpression());

    return std::make_shared<PrefixExpression>(cctx->parent->symbolTable, postfixExpression);
}
