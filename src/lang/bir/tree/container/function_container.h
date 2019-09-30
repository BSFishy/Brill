
#pragma once

#include <list>

#include "container.h"
#include "tree/function/function.h"

namespace Brill::IR {
    class FunctionContainer : public Container {
    public:
        std::list<Function> functions;
    };
}
