
#pragma once

#include <memory>
#include <string>

#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/IRBuilder.h"

namespace Brill::AST {
    struct CodegenContext {
        std::shared_ptr<llvm::LLVMContext> context;
        std::shared_ptr<llvm::Module> module;
        std::shared_ptr<llvm::IRBuilder<>> builder;

        explicit CodegenContext(std::string);
        CodegenContext(const std::shared_ptr<llvm::LLVMContext>&, const std::shared_ptr<llvm::Module>&, const std::shared_ptr<llvm::IRBuilder<>>&);
    };
}
