
#pragma once

#include "bir.h"

namespace Brill {
    namespace IR {
        /**
         * An object that represents a declaration. This is a parent class that is meant to encompass any sort of variable, function, class, etc. declaration.
         */
        class Declaration : public CodeGenerator {
        };
    }
}
