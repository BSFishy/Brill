
#pragma once

#include <list>
#include <memory>

#include "container.h"

namespace Brill::IR {
    class Protocol;

    class ProtocolContainer : public Container {
    public:
        std::list<std::shared_ptr<Protocol>> protocols;
    };
}
