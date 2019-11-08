
#pragma once

#include <vector>
#include <string>

#include "antlr4-runtime.h"

namespace Brill::AST {
    class Issue;

    class CompilerDiagnostics {
        std::vector<Issue> issues;
    public:
        void warn(antlr4::Token*, const std::string&);
        void error(antlr4::Token*, const std::string&);

        void addIssue(const Issue&);

        bool hasIssues() const;
        bool hasFatalIssues() const;
        void printIssues() const;
    };
}
