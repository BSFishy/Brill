
#include "prefix_expression.h"

#include "postfix/postfix_expression.h"
#include "lang/ast/abstract/convert_context.h"

using namespace Brill::AST;

PrefixExpression::PrefixExpression(const std::shared_ptr<SymbolTable> &st, const std::shared_ptr<PostfixExpression> &pe) : Node(st) {
    postfixExpression = pe;
}

llvm::Value *PrefixExpression::codegen(std::shared_ptr<CodegenContext> ctx) const {
    return this->postfixExpression->codegen(ctx);
}

std::shared_ptr<PrefixExpression> Brill::AST::convert(const std::shared_ptr<ConvertContext> &cctx, BrillParser::PrefixExpressionContext *ctx) {
    if (BrillParser::InoutExpressionContext *inoutContext = ctx->inoutExpression()) {
        cctx->error(inoutContext->getStart(), "In-out expressions are not implemented");
        return nullptr;
    }
    if (BrillParser::PrefixOperatorContext *operatorContext = ctx->prefixOperator()) {
        cctx->error(operatorContext->getStart(), "Prefix operators are not implemented");
        return nullptr;
    }

    std::shared_ptr<PostfixExpression> postfixExpression = convert(cctx, ctx->postfixExpression());
    if (!postfixExpression) {
        return nullptr;
    }

    return std::make_shared<PrefixExpression>(cctx->parent->getSymbolTable(), postfixExpression);
}
