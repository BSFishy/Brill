
#pragma once

#include <string>
#include <memory>

#include "node.h"

namespace Brill::AST {
    class NamedNode : public Node {
    public:
        std::string name;

        NamedNode() = delete;
        explicit NamedNode(std::string &n) : name(std::move(n)) {}
        NamedNode(std::string &n, SymbolTable* const& s) : Node(std::move(s)), name(std::move(n)) {}

        llvm::Value *codegen(std::shared_ptr<CodegenContext>) override = 0;
    };
}
