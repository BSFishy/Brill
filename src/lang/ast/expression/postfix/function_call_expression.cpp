
#include "function_call_expression.h"

#include "lang/ast/abstract/codegen_context.h"
#include "lang/ast/abstract/convert_context.h"

#include "util.h"

using namespace Brill::AST;

FunctionCallExpression::FunctionCallExpression(const std::shared_ptr<SymbolTable> &st, const std::shared_ptr<PostfixExpression> &pe) : PostfixExpression(st) {
    postfixExpression = pe;
}

llvm::Value *FunctionCallExpression::codegen(std::shared_ptr<CodegenContext> ctx) const {
    llvm::Function *function = (llvm::Function*) this->postfixExpression->codegen(ctx);
    if (!function) {
        throw IllegalStateException("Could not get function for call.");
    }

    return ctx->builder->CreateCall(function);
}

std::shared_ptr<FunctionCallExpression> Brill::AST::convert(const std::shared_ptr<ConvertContext> &cctx, BrillParser::FunctionCallExpressionContext *ctx) {
    std::shared_ptr<PostfixExpression> postfixExpression = convert(cctx, ctx->postfixExpression());

    return std::make_shared<FunctionCallExpression>(cctx->parent->getSymbolTable(), postfixExpression);
}
