
#pragma once

#include <list>

#include "container.h"
#include "tree/constructs/enum/enum.h"

namespace Brill::IR {
    class EnumContainer : public Container {
    public:
        std::list<Enum> enums;
    };
}
