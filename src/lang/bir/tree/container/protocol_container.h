
#pragma once

#include <list>

#include "container.h"
#include "tree/constructs/protocol/protocol.h"

namespace Brill::IR {
    class ProtocolContainer : public Container {
    public:
        std::list<Protocol> protocols;
    };
}
