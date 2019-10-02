
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
    };
}
