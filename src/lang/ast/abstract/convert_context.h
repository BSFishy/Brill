
#pragma once

#include <string>
#include <memory>

#include "antlr4-runtime.h"

namespace Brill::AST {
    class Node;
    class CompilerDiagnostics;

    struct ConvertContext {
        std::string moduleName;
        std::shared_ptr<Node> parent;
        std::shared_ptr<CompilerDiagnostics> diagnostics;

        explicit ConvertContext(std::string);
        ConvertContext(std::string, const std::shared_ptr<Node>&, const std::shared_ptr<CompilerDiagnostics>&);

        std::shared_ptr<ConvertContext> withParent(const std::shared_ptr<Node>&) const;

        void warn(antlr4::Token*, const std::string&);
        void error(antlr4::Token*, const std::string&);
    };
}
