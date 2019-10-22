
#include "function.h"

#include "util.h"

using namespace Brill::AST;

llvm::Value *Function::codegen(std::shared_ptr<CodegenContext> ctx) {
    throw NotImplementedException();
}

std::shared_ptr<Function> Brill::AST::convert(BrillParser::FunctionDeclarationContext *ctx) {
    throw NotImplementedException();
}
