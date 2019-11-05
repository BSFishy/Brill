
#include "statement_container.h"

#include "lang/ast/statement/statement.h"

using namespace Brill::AST;

void StatementContainer::addStatement(const std::shared_ptr<Statement>& statement) {
    this->statements.push_back(statement);
}

bool StatementContainer::removeStatement(const std::shared_ptr<Statement>& statement) {
    for (auto i = this->statements.begin(); i != this->statements.end(); ++i) {
        if (*i == statement) {
            this->statements.erase(i);
            return true;
        }
    }

    return false;
}

std::vector<std::shared_ptr<Statement>> StatementContainer::getStatements() const {
    return this->statements;
}

void StatementContainer::codegenStatements(const std::shared_ptr<CodegenContext>& ctx) const {
    for (std::shared_ptr<Statement> const& statement : this->statements) {
        statement->codegen(ctx);
    }
}
