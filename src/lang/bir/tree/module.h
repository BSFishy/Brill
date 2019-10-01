
#pragma once

#include <list>
#include <string>
#include <utility>
#include <memory>

#include "tree/container/variable_container.h"
#include "tree/container/function_container.h"
#include "tree/container/protocol_container.h"
#include "tree/container/class_container.h"
#include "tree/container/enum_container.h"
#include "tree/container/struct_container.h"
#include "tree/container/extension_container.h"

using namespace std;

namespace Brill::IR {
    /**
     * An object that represents a Brill module. This contains everything from classes, functions, global variables, extensions, etc.
     */
    class Module : public VariableContainer, public FunctionContainer, public ProtocolContainer, public ClassContainer, public EnumContainer, public StructContainer, public ExtensionContainer {
    public:
        std::string name;
        std::shared_ptr<Module> parent;

        explicit Module(std::string n) : name(std::move(n)), parent(nullptr) {}
        explicit Module(std::string n, std::shared_ptr<Module> p) : name(std::move(n)), parent(p) {}

        bool hasParent() {
            return parent != nullptr;
        }
    };
}
