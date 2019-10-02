
#pragma once

#include <list>
#include <memory>

#include "container.h"

namespace Brill::IR {
    class Enum;

    class EnumContainer : public Container {
    public:
        std::list<std::shared_ptr<Enum>> enums;
    };
}
