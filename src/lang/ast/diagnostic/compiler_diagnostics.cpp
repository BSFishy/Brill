
#include "compiler_diagnostics.h"

#include "issue.h"

using namespace Brill::AST;

void CompilerDiagnostics::warn(antlr4::Token *token, const std::string &message) {
    this->addIssue(Issue(IssueSeverity::warning, token->getCharPositionInLine(), token->getLine(), message));
}

void CompilerDiagnostics::error(antlr4::Token *token, const std::string &message) {
    this->addIssue(Issue(IssueSeverity::error, token->getCharPositionInLine(), token->getLine(), message));
}

void CompilerDiagnostics::addIssue(const Issue &issue) {
    this->issues.push_back(issue);
}

bool CompilerDiagnostics::hasIssues() const {
    return !this->issues.empty();
}

bool CompilerDiagnostics::hasFatalIssues() const {
    for (const auto &issue : this->issues) {
        if (isFatal(issue.getSeverity())) {
            return true;
        }
    }

    return false;
}

void CompilerDiagnostics::printIssues() const {
    for (const auto &issue : this->issues) {
        fprintf(stderr, "[%s] %s (%d:%d)\n", asString(issue.getSeverity()).c_str(), issue.getMessage().c_str(), issue.getLine(), issue.getColumn()+1);
    }
}
