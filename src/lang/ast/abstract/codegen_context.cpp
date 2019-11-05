
#include "codegen_context.h"

using namespace Brill::AST;

CodegenContext::CodegenContext(std::string filename) {
    context = std::make_shared<llvm::LLVMContext>();
    module = std::make_shared<llvm::Module>(filename, *context);
    builder = std::make_shared<llvm::IRBuilder<>>(*context);
}

CodegenContext::CodegenContext(const std::shared_ptr<llvm::LLVMContext> &c, const std::shared_ptr<llvm::Module> &m, const std::shared_ptr<llvm::IRBuilder<>> &b) {
    context = c;
    module = m;
    builder = b;
}
