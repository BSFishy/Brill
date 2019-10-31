
#pragma once

#include <vector>
#include <string>

#include "named_node.h"

namespace Brill::AST {
    class SymbolTable {
    public:
        std::vector<std::shared_ptr<NamedNode>> symbols;
        SymbolTable *parent;

        SymbolTable() = default;
        // SymbolTable() : parent(nullptr) {
        //     // symbols = new std::vector<NamedNode*>();
        // }
        // explicit SymbolTable(SymbolTable* const& p) : parent(p), symbols(new std::vector<NamedNode*>()) {}

        std::shared_ptr<NamedNode> find(std::string);
        void add(std::shared_ptr<NamedNode>);
        bool remove(std::shared_ptr<NamedNode>);
        std::shared_ptr<SymbolTable> child();

        int size();
        std::shared_ptr<NamedNode> get(int);
    };
}
