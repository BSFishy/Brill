
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
    if (BrillParser::TryOperatorContext *tryContext = ctx->tryOperator()) {
        cctx->error(tryContext->getStart(), "Try operators are not implemented");
        return nullptr;
    }
    if (BrillParser::BinaryExpressionsContext *binaryExpressionsContext = ctx->binaryExpressions()) {
        cctx->error(binaryExpressionsContext->getStart(), "Binary expressions are not implemented");
        return nullptr;
    }

    std::shared_ptr<PrefixExpression> prefixExpression = convert(cctx, ctx->prefixExpression());
    if (!prefixExpression) {
        return nullptr;
    }

    return std::make_shared<Expression>(cctx->parent->getSymbolTable(), prefixExpression);
}
