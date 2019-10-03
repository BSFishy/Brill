
#pragma once

#include <memory>

#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/IRBuilder.h"

namespace Brill::IR {
    struct CodegenContext {
        std::shared_ptr<llvm::LLVMContext> context;
        std::shared_ptr<llvm::Module> module;
        std::shared_ptr<llvm::IRBuilder<>> builder;

        explicit CodegenContext(std::shared_ptr<llvm::LLVMContext> &c, std::shared_ptr<llvm::Module> &m, std::shared_ptr<llvm::IRBuilder<>> &b) : context(c), module(m), builder(b) {}
    };
}
