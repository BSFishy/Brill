
#pragma once

#include <string>
#include <memory>
#include <utility>

#include "node.h"

namespace Brill::AST {
    class NamedNode : public virtual Node {
    public:
        std::string name;

        NamedNode() = delete;
        explicit NamedNode(std::string n) : Node(), name(std::move(n)) {}
        NamedNode(std::string n, const std::shared_ptr<SymbolTable> &s) : Node(s), name(std::move(n)) {}

        llvm::Value *codegen(std::shared_ptr<CodegenContext>) override = 0;
    };
}
