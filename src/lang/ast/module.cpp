
#include "module.h"

#include "util.h"

using namespace Brill::AST;

llvm::Value *Module::codegen(std::shared_ptr<CodegenContext> ctx) {
    throw NotImplementedException();
}

std::shared_ptr<Brill::AST::CodegenContext> Module::codegen() {
    throw NotImplementedException();
}

std::shared_ptr<Module> Brill::AST::convert(BrillParser::TopLevelContext *ctx) {
    throw NotImplementedException();
}
