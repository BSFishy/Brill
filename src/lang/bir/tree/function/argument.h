
#pragma once

#include <string>
#include <memory>

namespace Brill::IR {
    class Argument {
    public:
        std::string name;
        std::string type;

        explicit Argument(std::string n, std::string t) : name(std::move(n)), type(std::move(t)) {}
    };
}
