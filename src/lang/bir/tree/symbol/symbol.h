
#pragma once

#include <string>
#include <utility>

#include "tree/type.h"

namespace Brill::IR::Symbol {
    class Symbol {
    public:
        std::string name;
        std::unique_ptr<Brill::IR::Type> type;

        explicit Symbol(std::string n, std::unique_ptr<Brill::IR::Type> t) : name(std::move(n)), type(std::move(t)) {}
    };
}
