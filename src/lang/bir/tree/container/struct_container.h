
#pragma once

#include <list>
#include <memory>

#include "container.h"

namespace Brill::IR {
    class Struct;

    class StructContainer : public Container {
    public:
        std::list<std::shared_ptr<Struct>> structs;
    };
}
