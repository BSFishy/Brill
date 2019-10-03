
#pragma once

#include <memory>
#include <string>

#include "codegen_context.h"

namespace Brill::IR {
    class ValueGenerator {
    public:
        virtual std::string valuegen(std::shared_ptr<CodegenContext>) = 0;
    };
}
