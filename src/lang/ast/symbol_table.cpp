
#include "symbol_table.h"

#include "named_node.h"
#include <memory>

using namespace Brill::AST;

SymbolTable::SymbolTable() : symbols() {
    this->parent = nullptr;
}

SymbolTable::SymbolTable(const std::shared_ptr<const SymbolTable> &p) : symbols() {
    this->parent = p;
}

std::shared_ptr<NamedNode> SymbolTable::findFirst(const std::string &name) const {
    for (const auto &symbol : this->symbols) {
        if (symbol->getName() == name) {
            return symbol;
        }
    }

    if (this->parent) {
        return this->parent->findFirst(name);
    }

    return nullptr;
}

std::vector<std::shared_ptr<NamedNode>> SymbolTable::findAll(const std::string &name) const {
    std::vector<std::shared_ptr<NamedNode>> result;
    for (const auto &symbol : this->symbols) {
        if (symbol->getName() == name) {
            result.push_back(symbol);
        }
    }

    if (this->parent) {
        std::vector<std::shared_ptr<NamedNode>> parentResult = this->parent->findAll(name);
        result.insert(result.end(), parentResult.begin(), parentResult.end());
    }

    return result;
}

void SymbolTable::add(const std::shared_ptr<NamedNode> &node) {
    this->symbols.push_back(node);
}

bool SymbolTable::remove(const std::shared_ptr<NamedNode> &node) {
    for (auto i = this->symbols.begin(); i != this->symbols.end(); ++i) {
        if (*i == node) {
            this->symbols.erase(i);
            return true;
        }
    }

    return false;
}

std::shared_ptr<SymbolTable> SymbolTable::child() const {
    return std::make_shared<SymbolTable>(shared_from_this());
}

std::shared_ptr<const SymbolTable> SymbolTable::getParent() const {
    return this->parent;
}

// int SymbolTable::size() {
//     return this->symbols.size();
// }

// std::shared_ptr<NamedNode> SymbolTable::get(int index) {
//     return this->symbols[index];
// }
