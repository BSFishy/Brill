
#pragma once

#include <optional>
#include <utility>
#include <string>

#include "name.h"

namespace Brill::IR {
    class ParentedName : public Name {
    public:
        std::optional<Name> parent;

        explicit ParentedName() = default;

        explicit ParentedName(std::optional<Name> p) : parent(std::move(p)) {}
    };
}
