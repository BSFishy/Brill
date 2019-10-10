
#include "string_literal.h"

#include "llvm/IR/Value.h"

using namespace Brill::IR;

llvm::Value *StringLiteral::codegen(std::shared_ptr<CodegenContext> ctx) {
    return ctx->builder->CreateGlobalStringPtr(this->value);
}
