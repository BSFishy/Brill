
#pragma once

#include <list>

#include "container.h"
#include "tree/constructs/struct/struct.h"

namespace Brill::IR {
    class StructContainer : public Container {
    public:
        std::list<Struct> structs;
    };
}
