
#include "module.h"

#include <iostream>

#include "tree/function/function.h"

using namespace Brill::IR;

std::shared_ptr<CodegenContext> Module::codegen() {
    std::shared_ptr<llvm::LLVMContext> llvmContext = std::make_shared<llvm::LLVMContext>();
    std::shared_ptr<llvm::Module>      module      = std::make_shared<llvm::Module>("test", *llvmContext);
    std::shared_ptr<llvm::IRBuilder<>> builder     = std::make_shared<llvm::IRBuilder<>>(*llvmContext);

    module->setSourceFileName("-");
    std::shared_ptr<CodegenContext> ctx(new CodegenContext(llvmContext, module, builder));
    ctx->module->setPICLevel(llvm::PICLevel::Level::NotPIC);
    ctx->module->setPIELevel(llvm::PIELevel::Level::Default);

    for (std::shared_ptr<Function> const &function : this->functions) {
        function->codegen(ctx);
    }

    return ctx;
}
