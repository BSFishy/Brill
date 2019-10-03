
#pragma once

#include <list>
#include <memory>
#include <string>

#include "container.h"

namespace Brill::IR {
    class Function;

    class FunctionContainer : public Container {
    public:
        std::list<std::shared_ptr<Function>> functions;

        void addFunction(const std::shared_ptr<Function>&);
        std::shared_ptr<Function> getFunction(const std::string&);
        size_t functionCount();
    };
}
