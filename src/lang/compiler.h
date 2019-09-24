
#pragma once

#include <memory>

#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/IRBuilder.h"

using namespace llvm;

namespace Brill {
    struct CompileContext {
        LLVMContext context;
        IRBuilder<> builder;
        std::unique_ptr<Module> module;

        explicit CompileContext(StringRef name) : builder(context) {
            module = std::make_unique<Module>(name, context);
        };
    };

    class Compiler {
    public:
        static CompileContext* createContext(const char *);
    };
}
