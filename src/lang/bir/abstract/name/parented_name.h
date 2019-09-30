
#pragma once

#include <memory>
#include <utility>
#include <string>
#include <variant>

#include "name.h"

//#include "impl/class_name.h"
//#include "impl/enum_name.h"
//#include "impl/extension_name.h"
//#include "impl/function_name.h"
//#include "impl/module_name.h"
//#include "impl/protocol_name.h"
//#include "impl/struct_name.h"
//#include "impl/variable_name.h"

namespace Brill::IR {
    class ClassName;
    class EnumName;
    class ExtensionName;
    class FunctionName;
    class ModuleName;
    class ProtocolName;
    class StructName;
    class VariableName;

    using NameType = std::variant<ClassName, EnumName, ExtensionName, FunctionName, ModuleName, ProtocolName, StructName, VariableName>;

    class ParentedName : public Name {
    public:
        std::unique_ptr<NameType> parent;

        explicit ParentedName() : parent(nullptr) {}

        explicit ParentedName(NameType &p) {
            this->parent = std::unique_ptr<NameType>(std::make_unique<NameType>(p));
        }
    };
}
