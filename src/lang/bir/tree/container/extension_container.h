
#pragma once

#include <list>
#include <memory>

#include "container.h"

namespace Brill::IR {
    class Extension;

    class ExtensionContainer : public Container {
    public:
        std::list<std::shared_ptr<Extension>> extensions;
    };
}
