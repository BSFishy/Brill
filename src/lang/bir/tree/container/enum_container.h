
#pragma once

#include <list>

#include "container.h"

namespace Brill::IR {
    class Enum;

    class EnumContainer : public Container {
    public:
        std::list<Enum> enums;
    };
}
