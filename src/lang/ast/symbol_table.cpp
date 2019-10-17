
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

SymbolTable *SymbolTable::child() {
    return new SymbolTable(this);
}
