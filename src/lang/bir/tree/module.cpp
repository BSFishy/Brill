
#include "module.h"

#include <iostream>

#include "tree/function/function.h"

using namespace Brill::IR;

std::shared_ptr<CodegenContext> Module::codegen() {
    std::unique_ptr<llvm::LLVMContext> llvmContext;
    std::unique_ptr<llvm::Module> module;
    std::unique_ptr<llvm::IRBuilder<>> builder(new llvm::IRBuilder<>(*llvmContext));

    std::shared_ptr<CodegenContext> ctx(new CodegenContext(llvmContext, module, builder));

    for (std::shared_ptr<Function> const& function : this->functions) {
        fprintf(stderr, "Function: %s\n", function->name.c_str());
        if(auto * func = function->codegen(ctx)) {
            func->print(llvm::errs());
            fprintf(stderr, "\n");
        }
    }

    return ctx;
}
