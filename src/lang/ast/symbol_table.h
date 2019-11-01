
#pragma once

#include <vector>
#include <string>
#include <memory>

namespace Brill::AST {
    class NamedNode;

    class SymbolTable : public std::enable_shared_from_this<SymbolTable> {
    public:
        std::shared_ptr<std::vector<std::shared_ptr<NamedNode>>> symbols;
        std::shared_ptr<SymbolTable> parent;

        SymbolTable() {
            symbols = std::make_shared<std::vector<std::shared_ptr<NamedNode>>>();
            parent = nullptr;
        }

        std::shared_ptr<NamedNode> find(const std::string&);
        void add(const std::shared_ptr<NamedNode>&);
        bool remove(const std::shared_ptr<NamedNode>&);
        std::shared_ptr<SymbolTable> child();

        int size();
        std::shared_ptr<NamedNode> get(int);
    };
}
