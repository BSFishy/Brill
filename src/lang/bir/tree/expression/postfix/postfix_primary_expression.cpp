
#include "postfix_primary_expression.h"

using namespace Brill::IR;

llvm::Value *PostfixPrimaryExpression::codegen(std::shared_ptr<CodegenContext> ctx) {
    return this->primaryExpression->codegen(ctx);
}
