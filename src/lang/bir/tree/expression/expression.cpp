
#include "expression.h"

using namespace Brill::IR;

llvm::Value *Expression::codegen(std::shared_ptr<CodegenContext> ctx) {
    return this->prefixExpression->codegen(ctx);
}
