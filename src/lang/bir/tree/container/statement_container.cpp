
#include "statement_container.h"

using namespace Brill::IR;

void StatementContainer::addStatement(std::shared_ptr<Statement> s) {
    this->statements.push_back(s);
}

size_t StatementContainer::statementCount() {
    return this->statements.size();
}
