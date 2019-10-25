
#pragma once

#include <vector>
#include <string>

#include "named_node.h"

namespace Brill::AST {
    class SymbolTable {
    public:
        std::vector<NamedNode *> symbols;
        SymbolTable *parent;

        SymbolTable() : parent(nullptr) {}
        explicit SymbolTable(SymbolTable* const& p) : parent(p) {}

        NamedNode *find(std::string);
        void add(NamedNode *);
        bool remove(NamedNode *);
        SymbolTable *child();

        int size();
        NamedNode *get(int);
    };
}
