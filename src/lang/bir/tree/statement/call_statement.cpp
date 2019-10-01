
#include "call_statement.h"

using namespace Brill::IR;

llvm::Value *CallStatement::codegen(std::shared_ptr<CodegenContext> ctx) {
    llvm::Function *CalleeF = ctx->module->getFunction(this->name);
}
