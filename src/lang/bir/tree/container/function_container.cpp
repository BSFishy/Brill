
#include "function_container.h"
#include "tree/function/function.h"

using namespace Brill::IR;

void FunctionContainer::addFunction(const std::shared_ptr<Function> &function) {
    this->functions.push_back(function);
}

std::shared_ptr<Function> FunctionContainer::getFunction(const std::string &name) {
    for (std::shared_ptr<Function> const& f : this->functions) {
        if (f->name == name) {
            return f;
        }
    }

    return nullptr;
}

size_t FunctionContainer::functionCount() {
    return this->functions.size();
}
