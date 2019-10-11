
#pragma once

#include <list>
#include <memory>
#include <string>

#include "tree/abstract/codegen/named_code_generator.h"

namespace Brill::IR::Symbol {
    class SymbolTable {
    public:
        std::list<NamedCodeGenerator *> symbols;
        std::unique_ptr<SymbolTable> parent;

        explicit SymbolTable() = default;

        explicit SymbolTable(std::unique_ptr<SymbolTable> p) {
            this->parent = std::move(p);
        }

        void addSymbol(NamedCodeGenerator *symbol) {
            symbols.push_back(symbol);
        }

        NamedCodeGenerator *find(std::string name) {
            for (NamedCodeGenerator* const& symbol : symbols) {
                
            }

            return nullptr;
        }
    };
}
