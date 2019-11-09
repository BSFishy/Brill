
#include "value_wrapper.h"

#include "llvm/ADT/StringRef.h"

using namespace Brill::AST;

ValueWrapper::ValueWrapper(const std::shared_ptr<SymbolTable> &st, llvm::Value *v) : Node(st), NamedNode(v->getName()) {
    this->value = v;
}

ValueWrapper::~ValueWrapper() {
    this->value->deleteValue();
}

std::string ValueWrapper::getName() const {
    return this->value->getName();
}

llvm::Value *ValueWrapper::codegen(std::shared_ptr<CodegenContext>) const {
    return this->value;
}
