
#pragma once

#include <utility>
#include <string>
#include <optional>

#include "abstract/name/mangleable.h"
#include "abstract/name/parented_name.h"

#include "module_name.h"

namespace Brill::IR {
    class ExtensionName : public Mangleable, public ParentedName {
    public:
        explicit ExtensionName(std::string n) : ParentedName(), name(std::move(n)) {}

        explicit ExtensionName(std::optional<ModuleName> p, std::string n) : ParentedName(p), name(std::move(n)) {}

        std::string stringValue() override;

        mangled_name mangle() override;

        demangled_name demangle(mangled_name) override;

    private:
        std::string name;
    };
}
