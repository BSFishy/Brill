
#include "issue.h"

using namespace Brill::AST;

bool Brill::AST::isFatal(IssueSeverity severity) {
    switch (severity) {
        case IssueSeverity::warning: return false;
        case IssueSeverity::error: return true;
        default: return true;
    }
}

std::string Brill::AST::asString(IssueSeverity severity) {
    switch (severity) {
        case IssueSeverity::warning: return "WARNING";
        case IssueSeverity::error: return "ERROR";
        default: return "UNKNOWN";
    }
}

Issue::Issue(IssueSeverity s, int c, int l, const std::string &m) : column(c), line(l), message(m) {
    this->severity = s;
}

IssueSeverity Issue::getSeverity() const {
    return this->severity;
}

std::string Issue::getMessage() const {
    return this->message;
}

int Issue::getColumn() const {
    return this->column;
}

int Issue::getLine() const {
    return this->line;
}
