
#pragma once

#include <list>
#include <optional>

#include "symbol.h"

namespace Brill::IR::Symbol {
    class SymbolTable {
    public:
        std::list<Symbol> symbols;
        std::optional<std::unique_ptr<SymbolTable>> parent;

        explicit SymbolTable() = default;

        explicit SymbolTable(std::unique_ptr<SymbolTable> p) : parent(std::make_optional(p)) {}
    };
}
