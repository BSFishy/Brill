
#pragma once

#include <list>

#include "container.h"

namespace Brill::IR {
    class Variable;

    class VariableContainer : public Container {
    public:
        std::list<Variable> variables;
    };
}
