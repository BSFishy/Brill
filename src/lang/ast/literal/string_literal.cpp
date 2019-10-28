
#include "string_literal.h"

using namespace Brill::AST;

llvm::Value *StringLiteral::codegen(std::shared_ptr<CodegenContext> ctx) {
    return ctx->builder->CreateGlobalStringPtr(this->value);
}
