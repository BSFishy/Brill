
#pragma once

#include <list>

#include "container.h"

namespace Brill::IR {
    class Protocol;

    class ProtocolContainer : public Container {
    public:
        std::list<Protocol> protocols;
    };
}
