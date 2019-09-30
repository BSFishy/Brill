
#pragma once

#include <list>

#include "container.h"
#include "tree/constructs/extension/extension.h"

namespace Brill::IR {
    class ExtensionContainer : public Container {
    public:
        std::list<Extension> extensions;
    };
}
