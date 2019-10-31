
#pragma once

#include <vector>
#include <string>
#include <memory>

namespace Brill::AST {
    class NamedNode;

    class SymbolTable : public std::enable_shared_from_this<SymbolTable> {
    public:
        std::vector<std::shared_ptr<NamedNode>> symbols;
        std::shared_ptr<SymbolTable> parent;

        // SymbolTable() = default;
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
