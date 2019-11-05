
#include "function_container.h"

#include "lang/ast/symbol_table.h"
#include "lang/ast/function/function.h"

using namespace Brill::AST;

void FunctionContainer::addFunction(const std::shared_ptr<Function> &function) {
    this->getSymbolTable()->add(function);
    this->functions.push_back(function);
}

bool FunctionContainer::removeFunction(const std::shared_ptr<Function> &function) {
    for (auto i = this->functions.begin(); i != this->functions.end(); ++i) {
        if (*i == function) {
            this->functions.erase(i);
            return this->getSymbolTable()->remove(function);
        }
    }

    this->getSymbolTable()->remove(function);
    return false;
}

std::shared_ptr<Function> FunctionContainer::getFunction(const std::string &name) const {
    for(std::shared_ptr<Function> const& function : this->functions) {
        if (function->getName() == name) {
            return function;
        }
    }

    return nullptr;
}

std::vector<std::shared_ptr<Function>> FunctionContainer::getFunctions() const {
    return this->functions;
}

void FunctionContainer::codegenFunctions(const std::shared_ptr<CodegenContext> &ctx) const {
    for (std::shared_ptr<Function> const& function : this->functions) {
        function->codegen(ctx);
    }
}
