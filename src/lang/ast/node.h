
#pragma once

#include <memory>

#include "llvm/IR/Value.h"

#include "abstract/codegen_context.h"

namespace Brill::AST {
    class SymbolTable;

    class Node {
    public:
        std::shared_ptr<SymbolTable> symbolTable;

        Node() = default;
        explicit Node(std::shared_ptr<SymbolTable> const& s) {
            symbolTable = s;
        }

        virtual llvm::Value *codegen(std::shared_ptr<CodegenContext>) = 0;

        std::shared_ptr<SymbolTable> getSymbolTable() {
            return this->symbolTable;
        }
    };
}
