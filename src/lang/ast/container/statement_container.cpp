
#include "statement_container.h"

#include "lang/ast/statement/statement.h"

using namespace Brill::AST;

void StatementContainer::addStatement(std::shared_ptr<Statement> statement) {
    // this->symbolTable->add(statement);
    this->statements.push_back(statement);
}

bool StatementContainer::removeStatement(std::shared_ptr<Statement> statement) {
    for (auto i = this->statements.begin(); i != this->statements.end(); ++i) {
        if (*i == statement) {
            this->statements.erase(i);
            // return this->symbolTable->remove(statement);
            return true;
        }
    }

    // this->symbolTable->remove(statement);
    return false;
}

void StatementContainer::codegenStatements(std::shared_ptr<CodegenContext> ctx) {
    for (std::shared_ptr<Statement> const& statement : this->statements) {
        statement->codegen(ctx);
    }
}
