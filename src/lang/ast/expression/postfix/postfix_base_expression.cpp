
#include "postfix_base_expression.h"

#include "lang/ast/expression/primary/primary_expression.h"
#include "postfix_dot_expression.h"

#include "util.h"

using namespace Brill::AST;

llvm::Value *PostfixBaseExpression::codegen(std::shared_ptr<CodegenContext> ctx) {
    llvm::Value *value = this->primaryExpression->codegen(ctx);

    if (this->dotExpression) {
        throw NotImplementedException();
    }

    return value;
}

std::shared_ptr<PostfixBaseExpression> Brill::AST::convert(std::shared_ptr<ConvertContext> cctx, BrillParser::PostfixBaseExpressionContext *ctx) {
    std::shared_ptr<PrimaryExpression> primaryExpression = convert(cctx, ctx->primaryExpression());

    std::shared_ptr<PostfixDotExpression> dotExpression = nullptr;
    if (BrillParser::PostfixDotExpressionContext *dotContext = ctx->postfixDotExpression()) {
        dotExpression = convert(cctx, dotContext);
    }

    return std::make_shared<PostfixBaseExpression>(primaryExpression, dotExpression);
}
