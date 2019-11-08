
#pragma once

#include <string>

namespace Brill::AST {
    enum class IssueSeverity { warning, error };
    bool isFatal(IssueSeverity);
    std::string asString(IssueSeverity);

    class Issue {
        IssueSeverity severity;
        std::string message;

        int column;
        int line;
    public:
        Issue(IssueSeverity, int, int, const std::string&);

        IssueSeverity getSeverity() const;
        std::string getMessage() const;
        int getColumn() const;
        int getLine() const;
    };
}
