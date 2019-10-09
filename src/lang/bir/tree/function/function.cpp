
#include "function.h"

#include <vector>

#include "llvm/IR/Verifier.h"

#include "util.h"

using namespace Brill::IR;

llvm::Value *Function::codegen(std::shared_ptr<CodegenContext> ctx) {
    std::vector<llvm::Type *> args;
    for (std::shared_ptr<Argument> const& arg : this->arguments) {
        if (arg->type == "i8") {
            args.push_back(llvm::Type::getInt8PtrTy(*(ctx->context)));
        } else {
            throw NotImplementedException();
        }
    }

    llvm::FunctionType *functionType = llvm::FunctionType::get(llvm::Type::getVoidTy(*(ctx->context)), args, this->varargs);

    // std::string name = (this->name == "main") ? "_start" : this->name;
    std::string name = this->name;
    llvm::Function *function = llvm::Function::Create(functionType, llvm::Function::ExternalLinkage, name, *(ctx->module));

    if (!function) {
        throw IllegalStateException("Could not generate function: " + this->name);
    }

    unsigned index = 0;
    for (llvm::Argument &arg : function->args()) {
        arg.setName(this->arguments[index++]->name);
    }

    if (!this->statements.empty()) {
        llvm::BasicBlock *block = llvm::BasicBlock::Create(*(ctx->context), "entry", function);
        ctx->builder->SetInsertPoint(block);

        for (std::shared_ptr<Statement> const &statement : this->statements) {
            statement->codegen(ctx);
        }

        ctx->builder->CreateRetVoid();
    }

    llvm::verifyFunction(*function);

    return function;
}
