
#pragma once

#include <utility>
#include <string>
#include <memory>

#include "abstract/name/mangleable.h"
#include "abstract/name/parented_name.h"

namespace Brill::IR {
    class StructName : public Mangleable, public ParentedName {
    public:
        explicit StructName(std::string n) : ParentedName(), name(std::move(n)) {}

        explicit StructName(NameType& p, std::string n) : ParentedName(p), name(std::move(n)) {}

        std::string stringValue() override;

        mangled_name mangle() override;

        demangled_name demangle(mangled_name) override;

    private:
        std::string name;
    };
}
