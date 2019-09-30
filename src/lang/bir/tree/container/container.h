
#pragma once

#include "tree/symbol/symbol_table.h"

namespace Brill::IR {
    /**
     * A generic type container. This could contain anything from classes to variables. It is meant to be subclassed to provide lists and helper
     * methods to assist in manipulating the types being contained.
     */
    class Container {
    public:
        Symbol::SymbolTable symbolTable;
    };
}
