
#pragma once

#include <memory>

#include "llvm/IR/Value.h"

#include "abstract/codegen_context.h"

namespace Brill::AST {
    class SymbolTable;

    class Node {
    public:
        SymbolTable *symbolTable;

        Node() = default;
        explicit Node(SymbolTable* const& s) : symbolTable(std::move(s)) {}

        virtual llvm::Value *codegen(std::shared_ptr<CodegenContext>) = 0;
    };
}
