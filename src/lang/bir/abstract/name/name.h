
#pragma once

#include <string>

namespace Brill {
    namespace IR {
        /**
         * The name of some object in the hierarchy. This could be a module name, file name, class name, or anything else that has a name.
         * It is meant to be subclassed to allow outside accessors to convert the name into a string, and potentially mangle it.
         */
        class Name {
        public:
            virtual std::string stringValue() = 0;
        };
    }
}
