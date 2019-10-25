
#include "function_container.h"

#include "lang/ast/function/function.h"

using namespace Brill::AST;

void FunctionContainer::addFunction(Function *function) {
    this->symbolTable->add(function);
    this->functions.push_back(function);
}

bool FunctionContainer::removeFunction(Function *function) {
    for (auto i = this->functions.begin(); i != this->functions.end(); ++i) {
        if (*i == function) {
            this->functions.erase(i);
            return this->symbolTable->remove(function);
        }
    }

    this->symbolTable->remove(function);
    return false;
}

Function *FunctionContainer::getFunction(std::string name) {
    for(Function* const& function : this->functions) {
        if (function->name == name) {
            return function;
        }
    }

    return nullptr;
}

void FunctionContainer::codegenFunctions(std::shared_ptr<CodegenContext> ctx) {
    for (Function* const& function : this->functions) {
        function->codegen(ctx);
    }
}
