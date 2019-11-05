
#pragma once

#include <memory>

#include "llvm/IR/Value.h"

#include "symbol_table.h"

namespace Brill::AST {
    class CodegenContext;
    class ConvertContext;

    /**
     * A node in the Brill AST. This represents any peice of the AST and contains a symbol table.
     * The symbol table can be provided and provides this node or child nodes with any symbol
     * available in the current scope.
     */
    class Node {
        std::shared_ptr<SymbolTable> symbolTable;
    public:
        Node();
        explicit Node(const std::shared_ptr<SymbolTable>&);

        /**
         * Get the symbol table. This is the symbol table for this node and can be used to get
         * a symbol in the current scope. This might be inherited from a parent node or a
         * new one can be generated for this node.
         */
        std::shared_ptr<SymbolTable> getSymbolTable() const;

        /**
         * Perform code generation for this node. This will take the current code generation context
         * and use it to generate the necessary LLVM instructions that are equivalent to this node.
         */
        virtual llvm::Value *codegen(std::shared_ptr<CodegenContext>) const = 0;
    };
}
