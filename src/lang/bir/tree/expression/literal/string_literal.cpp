
#include "string_literal.h"

#include "llvm/IR/Constants.h"

using namespace Brill::IR;

llvm::Value *StringLiteral::codegen(std::shared_ptr<CodegenContext> ctx) {
    return llvm::ConstantDataArray::getString(*(ctx->context), this->value);
}
