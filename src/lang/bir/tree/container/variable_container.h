
#pragma once

#include <list>
#include <memory>

#include "container.h"

namespace Brill::IR {
    class Variable;

    class VariableContainer : public Container {
    public:
        std::list<std::shared_ptr<Variable>> variables;

        void addVariable(std::shared_ptr<Variable>);
        size_t variableCount();
    };
}
