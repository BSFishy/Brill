
#pragma once

#include <string>

#include "abstract/name/mangleable.h"

namespace Brill {
    namespace IR {
        class ModuleName : public Mangleable {
        public:
            explicit ModuleName(std::string);

            std::string stringValue() override;
            mangled_name mangle() override;
            demangled_name demangle(mangled_name) override;
        private:
            std::string name;
        };
    }
}
