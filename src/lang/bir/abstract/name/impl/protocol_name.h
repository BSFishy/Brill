
#pragma once

#include <utility>
#include <string>
#include <optional>

#include "abstract/name/mangleable.h"
#include "abstract/name/parented_name.h"

namespace Brill::IR {
    class ProtocolName : public Mangleable, public ParentedName {
    public:
        explicit ProtocolName(std::string n) : ParentedName(), name(std::move(n)) {}

        explicit ProtocolName(NameType &p, std::string n) : ParentedName(p), name(std::move(n)) {}

        std::string stringValue() override;

        mangled_name mangle() override;

        demangled_name demangle(mangled_name) override;

    private:
        std::string name;
    };
}
