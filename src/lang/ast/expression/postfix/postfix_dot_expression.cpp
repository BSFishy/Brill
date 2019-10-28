
#include "postfix_dot_expression.h"

#include "util.h"

using namespace Brill::AST;

llvm::Value *PostfixDotExpression::codegen(std::shared_ptr<CodegenContext> ctx) {
    throw NotImplementedException();
}

std::shared_ptr<PostfixDotExpression> Brill::AST::convert(std::shared_ptr<ConvertContext> cctx, BrillParser::PostfixDotExpressionContext *ctx) {
    throw NotImplementedException();
}
