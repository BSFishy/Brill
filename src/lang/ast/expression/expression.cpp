
#include "expression.h"

#include "prefix_expression.h"
#include "lang/ast/abstract/convert_context.h"

using namespace Brill::AST;

Expression::Expression(const std::shared_ptr<SymbolTable> &st, const std::shared_ptr<PrefixExpression> &pe) : Node(st) {
    this->prefixExpression = pe;
}

llvm::Value *Expression::codegen(std::shared_ptr<CodegenContext> ctx) const {
    return this->prefixExpression->codegen(ctx);
}

std::shared_ptr<Expression> Brill::AST::convert(const std::shared_ptr<ConvertContext> &cctx, BrillParser::ExpressionContext *ctx) {
    std::shared_ptr<PrefixExpression> prefixExpression = convert(cctx, ctx->prefixExpression());

    return std::make_shared<Expression>(cctx->parent->getSymbolTable(), prefixExpression);
}
