
#include "function_call_expression.h"

#include "util.h"

using namespace Brill::AST;

llvm::Value *FunctionCallExpression::codegen(std::shared_ptr<CodegenContext> ctx) {
    llvm::Function *function = (llvm::Function*) this->postfixExpression->codegen(ctx);
    if (!function) {
        throw IllegalStateException("Could not get function for call.");
    }

    return ctx->builder->CreateCall(function);
}

std::shared_ptr<FunctionCallExpression> Brill::AST::convert(const std::shared_ptr<ConvertContext> &cctx, BrillParser::FunctionCallExpressionContext *ctx) {
    std::shared_ptr<PostfixExpression> postfixExpression = convert(cctx, ctx->postfixExpression());

    return std::make_shared<FunctionCallExpression>(cctx->parent->symbolTable, postfixExpression);
}
