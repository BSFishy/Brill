
#pragma once

#include <list>
#include <memory>
#include <string>

#include "container.h"

namespace Brill::IR {
    class Class;

    class ClassContainer : public Container {
    public:
        std::list<std::shared_ptr<Class>> classes;

        void addClass(const std::shared_ptr<Class>&);
        std::shared_ptr<Class> getClass(const std::string&);
        size_t classCount();
    };
}
