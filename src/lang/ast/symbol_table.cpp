
#include "symbol_table.h"

using namespace Brill::AST;

NamedNode *SymbolTable::find(std::string name) {
    for (NamedNode* const& symbol : symbols) {
        if (symbol->name == name) {
            return symbol;
        }
    }

    if (NamedNode *symbol = this->parent->find(name)) {
        return symbol;
    }

    return nullptr;
}

void SymbolTable::add(NamedNode *node) {
    this->symbols.push_back(node);
}

bool SymbolTable::remove(NamedNode *node) {
    for (auto i = this->symbols.begin(); i != this->symbols.end(); ++i) {
        if (*i == node) {
            this->symbols.erase(i);
            return true;
        }
    }

    return false;
}

SymbolTable *SymbolTable::child() {
    return new SymbolTable(this);
}

int SymbolTable::size() {
    return this->symbols.size();
}

NamedNode *SymbolTable::get(int index) {
    return this->symbols[index];
}
