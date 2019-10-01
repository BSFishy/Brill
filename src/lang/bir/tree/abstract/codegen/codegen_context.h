
#pragma once

#include <memory>

#include "llvm/IR/Value.h"
#include "llvm/IR/Module.h"

namespace Brill::IR {
    struct CodegenContext {
        std::shared_ptr<llvm::LLVMContext> context;
        std::shared_ptr<llvm::Module> module;
    };
}
