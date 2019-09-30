
#pragma once

#include <list>
#include <memory>

#include "symbol.h"

namespace Brill::IR::Symbol {
    class SymbolTable {
    public:
        std::list<Symbol> symbols;
        std::unique_ptr<SymbolTable> parent;

        explicit SymbolTable() = default;

        explicit SymbolTable(std::unique_ptr<SymbolTable> p) {
            this->parent = std::move(p);
        }
    };
}
