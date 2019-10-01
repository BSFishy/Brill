
#pragma once

#include <list>

#include "container.h"

namespace Brill::IR {
    class Function;

    class FunctionContainer : public Container {
    public:
        std::list<Function> functions;
    };
}
