
#pragma once

#include "tree/abstract/codegen/code_generator.h"

namespace Brill::IR {
    /**
     * An object that represents a declaration. This is a parent class that is meant to encompass any sort of variable, function, class, etc. declaration.
     */
    class Declaration : public CodeGenerator {
    };
}
