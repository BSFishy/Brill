
#pragma once

#include <memory>

#include "llvm/IR/Value.h"

#include "abstract/codegen_context.h"
#include "symbol_table.h"

namespace Brill::AST {
    class Node {
    public:
        std::shared_ptr<SymbolTable> symbolTable;

        Node() {
            symbolTable = std::make_shared<SymbolTable>();
        }

        explicit Node(std::shared_ptr<SymbolTable> const& s) {
            symbolTable = s;
        }

        virtual llvm::Value *codegen(std::shared_ptr<CodegenContext>) = 0;
    };
}
