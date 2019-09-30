
#pragma once

#include <list>

#include "container.h"
#include "tree/variable/variable.h"

namespace Brill::IR {
    class VariableContainer : public Container {
    public:
        std::list<Variable> variables;
    };
}
