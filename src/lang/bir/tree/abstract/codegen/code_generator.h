
#pragma once

#include <memory>

#import "llvm/IR/Value.h"

#include "codegen_context.h"

namespace Brill::IR {
    /**
     * An object that generates some sort of code. This is an object that contains the `codegen` function to allow the object
     * to generate some sort of LLVM code. The default return type of the method is an `llvm::Value*` which is the base type
     * for all LLVM code generation types, so this should be sufficient enough to be able to generate code for almost any type.
     */
    class CodeGenerator {
    public:
        virtual llvm::Value *codegen(std::shared_ptr<CodegenContext>) = 0;
    };
}
