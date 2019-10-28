
#include "postfix_expression.h"

#include "postfix_base_expression.h"
#include "postfix_function_expression.h"
#include "postfix_post_expression.h"

#include "util.h"

using namespace Brill::AST;

llvm::Value *PostfixExpression::codegen(std::shared_ptr<CodegenContext> ctx) {
    llvm::Value *value = this->baseExpression->codegen(ctx);

    if (this->functionExpression) {
        throw NotImplementedException();
    }

    if (this->postExpression) {
        throw NotImplementedException();
    }

    return value;
}

std::shared_ptr<PostfixExpression> Brill::AST::convert(std::shared_ptr<ConvertContext> cctx, BrillParser::PostfixExpressionContext *ctx) {
    std::shared_ptr<PostfixBaseExpression> baseExpression = convert(cctx, ctx->postfixBaseExpression());
    if (!baseExpression) {
        throw IllegalStateException("Could not convert base expression");
    }

    std::shared_ptr<PostfixFunctionExpression> functionExpression = nullptr;
    std::shared_ptr<PostfixPostExpression> postExpression = nullptr;
    if (BrillParser::PostfixFunctionExpressionContext *functionContext = ctx->postfixFunctionExpression()) {
        functionExpression = convert(cctx, functionContext);
    }
    if (BrillParser::PostfixPostExpressionContext *postContext = ctx->postfixPostExpression()) {
        postExpression = convert(cctx, postContext);
    }

    return std::make_shared<PostfixExpression>(baseExpression, functionExpression, postExpression);
}
