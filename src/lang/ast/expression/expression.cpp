
#include "expression.h"

using namespace Brill::AST;

llvm::Value *Expression::codegen(std::shared_ptr<CodegenContext> ctx) {
    return this->prefixExpression->codegen(ctx);
}

std::shared_ptr<Expression> Brill::AST::convert(const std::shared_ptr<ConvertContext> &cctx, BrillParser::ExpressionContext *ctx) {
    std::shared_ptr<PrefixExpression> prefixExpression = convert(cctx, ctx->prefixExpression());

    return std::make_shared<Expression>(cctx->parent->symbolTable, prefixExpression);
}
