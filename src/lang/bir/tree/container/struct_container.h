
#pragma once

#include <list>

#include "container.h"

namespace Brill::IR {
    class Struct;

    class StructContainer : public Container {
    public:
        std::list<Struct> structs;
    };
}
