
#pragma once

#include <memory>

#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/IRBuilder.h"

namespace Brill::IR {
    struct CodegenContext {
        std::unique_ptr<llvm::LLVMContext> context;
        std::unique_ptr<llvm::Module> module;
        std::unique_ptr<llvm::IRBuilder<>> builder;

        explicit CodegenContext(std::unique_ptr<llvm::LLVMContext> &c, std::unique_ptr<llvm::Module> &m, std::unique_ptr<llvm::IRBuilder<>> &b) : context(std::move(c)), module(std::move(m)), builder(std::move(b)) {}
    };
}
