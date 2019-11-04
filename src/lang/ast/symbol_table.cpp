
#include "symbol_table.h"

#include "named_node.h"

using namespace Brill::AST;

std::shared_ptr<NamedNode> SymbolTable::find(const std::string &name) {
    for (const auto &symbol : this->symbols) {
        if (symbol->name == name) {
            return symbol;
        }
    }

    if (this->parent) {
        return this->parent->find(name);
    }

    return nullptr;
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

std::shared_ptr<SymbolTable> SymbolTable::child() {
    std::shared_ptr<SymbolTable> c = std::make_shared<SymbolTable>();
    c->parent = shared_from_this();
    return c;
}

int SymbolTable::size() {
    return this->symbols.size();
}

std::shared_ptr<NamedNode> SymbolTable::get(int index) {
    return this->symbols[index];
}
