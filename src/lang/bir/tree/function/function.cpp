
#include "function.h"

void Brill::IR::Function::addStatement(std::unique_ptr<Statement> s) {
    this->statements.push_back(std::move(s));
}
