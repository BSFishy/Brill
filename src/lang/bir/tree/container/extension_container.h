
#pragma once

#include <list>

#include "container.h"

namespace Brill::IR {
    class Extension;

    class ExtensionContainer : public Container {
    public:
        std::list<Extension> extensions;
    };
}
