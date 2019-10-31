
#pragma once

#include <string>
#include <memory>

#include "node.h"

namespace Brill::AST {
    class NamedNode : public virtual Node {
    public:
        std::string name;

        NamedNode() = delete;
        explicit NamedNode(const std::string &n) : name(std::move(n)) {}
        NamedNode(const std::string &n, std::shared_ptr<SymbolTable> const& s) : Node(s), name(std::move(n)) {}

        llvm::Value *codegen(std::shared_ptr<CodegenContext>) override = 0;
    };
}
