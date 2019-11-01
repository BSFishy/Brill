
#include "postfix_primary_expression.h"

#include "lang/ast/expression/primary/primary_expression.h"

#include "util.h"

using namespace Brill::AST;

llvm::Value *PostfixPrimaryExpression::codegen(std::shared_ptr<CodegenContext> ctx) {
    return this->primaryExpression->codegen(ctx);
}

std::shared_ptr<PostfixPrimaryExpression> Brill::AST::convert(const std::shared_ptr<ConvertContext> &cctx, BrillParser::PostfixPrimaryExpressionContext *ctx) {
    printf("Text: %s\nString: %s\nString tree: %s\n", ctx->getText().c_str(), ctx->toString().c_str(), ctx->toStringTree().c_str());
    for (auto const& child : ctx->children) {
        printf("\t%s -- %s\n", child->getText().c_str(), child->toStringTree().c_str());
    }

    return std::make_shared<PostfixPrimaryExpression>(convert(cctx, ctx->primaryExpression()));
}
