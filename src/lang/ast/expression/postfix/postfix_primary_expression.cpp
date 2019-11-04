
#include "postfix_primary_expression.h"

#include "lang/ast/expression/primary/primary_expression.h"

#include "util.h"

using namespace Brill::AST;

llvm::Value *PostfixPrimaryExpression::codegen(std::shared_ptr<CodegenContext> ctx) {
    return this->primaryExpression->codegen(ctx);
}

std::shared_ptr<PostfixPrimaryExpression> Brill::AST::convert(const std::shared_ptr<ConvertContext> &cctx, BrillParser::PostfixPrimaryExpressionContext *ctx) {
    return std::make_shared<PostfixPrimaryExpression>(cctx->parent->symbolTable, convert(cctx, ctx->primaryExpression()));
}
