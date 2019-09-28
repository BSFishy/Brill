
#pragma once

#include "bir.h"

namespace Brill::IR {
    /**
     * An object that has a name. This could be any object in the hierarchy that has a name, including but not limited to variables, classes,
     * functions, etc. Normally, named types should inherit the `Mangleable` class because in most situations, names should be mangled.
     */
    class Named {
    public:
        virtual Brill::IR::Name getName() = 0;
    };
}
