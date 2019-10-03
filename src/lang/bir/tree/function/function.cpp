
#include "function.h"

#include "util.h"

using namespace Brill::IR;

llvm::Value *Function::codegen(std::shared_ptr<CodegenContext> ctx) {
    llvm::FunctionType *functionType = llvm::FunctionType::get(llvm::Type::getVoidTy(*(ctx->context)), false);
    llvm::Function *function = llvm::Function::Create(functionType, llvm::Function::ExternalLinkage, this->name, *(ctx->module));

    if (!function) {
        throw IllegalStateException("Could not generate function: " + this->name);
    }

    if (!this->statements.empty()) {
        llvm::BasicBlock *block = llvm::BasicBlock::Create(*(ctx->context), "entry", function);
        ctx->builder->SetInsertPoint(block);

        for (std::shared_ptr<Statement> const &statement : this->statements) {
            statement->codegen(ctx);
        }

        ctx->builder->CreateRetVoid();
    }

    return function;
}
