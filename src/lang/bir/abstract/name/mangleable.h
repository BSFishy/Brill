
#pragma once

#include <string>

#include "name.h"

namespace Brill {
    namespace IR {
        using mangled_name = std::string;
        using demangled_name = std::string;

        class Mangleable : public Name {
        public:
            virtual mangled_name mangle() = 0;
            virtual demangled_name demangle(mangled_name) = 0;
        };
    }
}
