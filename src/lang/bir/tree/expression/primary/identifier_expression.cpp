
#include "identifier_expression.h"

using namespace Brill::IR;

llvm::Value *IdentifierExpression::codegen(std::shared_ptr<CodegenContext> ctx) {
    return ctx->module->getFunction(this->value);
}
