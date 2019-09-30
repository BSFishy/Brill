
#pragma once

#include <list>

#include "container.h"
#include "tree/constructs/class/class.h"

namespace Brill::IR {
    class ClassContainer : public Container {
    public:
        std::list<Class> classes;
    };
}
