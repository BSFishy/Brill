
#include "string_literal.h"

#include "lang/ast/abstract/codegen_context.h"

using namespace Brill::AST;

StringLiteral::StringLiteral(const std::shared_ptr<SymbolTable> &st, std::string v) : Literal(st), value(std::move(v)) {}

llvm::Value *StringLiteral::codegen(std::shared_ptr<CodegenContext> ctx) const {
    return ctx->builder->CreateGlobalStringPtr(this->value);
}
