
#pragma once

#include <string>

#include "tree/container/variable_container.h"
#include "tree/container/function_container.h"
#include "tree/container/protocol_container.h"
#include "tree/container/class_container.h"
#include "tree/container/enum_container.h"
#include "tree/container/struct_container.h"

namespace Brill::IR {
    class Class : public VariableContainer, public FunctionContainer, public ClassContainer, public ProtocolContainer, public EnumContainer, public StructContainer {
    public:
        std::string name;
    };
}
