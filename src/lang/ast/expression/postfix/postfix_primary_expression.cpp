
#include "postfix_primary_expression.h"

#include "lang/ast/abstract/convert_context.h"
#include "lang/ast/expression/primary/primary_expression.h"

#include "util.h"

using namespace Brill::AST;

PostfixPrimaryExpression::PostfixPrimaryExpression(const std::shared_ptr<SymbolTable> &st, const std::shared_ptr<PrimaryExpression> &pe) : PostfixExpression(st) {
    primaryExpression = pe;
}

llvm::Value *PostfixPrimaryExpression::codegen(std::shared_ptr<CodegenContext> ctx) const {
    return this->primaryExpression->codegen(ctx);
}

std::shared_ptr<PostfixPrimaryExpression> Brill::AST::convert(const std::shared_ptr<ConvertContext> &cctx, BrillParser::PostfixPrimaryExpressionContext *ctx) {
    return std::make_shared<PostfixPrimaryExpression>(cctx->parent->getSymbolTable(), convert(cctx, ctx->primaryExpression()));
}
