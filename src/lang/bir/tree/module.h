
#pragma once

#include <list>
#include <string>
#include <utility>
#include <optional>

#include "bir.h"

using namespace std;

namespace Brill::IR {
    class ModuleName;

    class ImportDeclaration;

    class Variable;

    class Function;

    class Protocol;

    class Class;

    class Enum;

    class Struct;

    class Extension;

    /**
     * An object that represents a Brill module. This contains everything from classes, functions, global variables, extensions, etc.
     */
    class Module : public VariableContainer, public FunctionContainer, public ProtocolContainer, public ClassContainer, public EnumContainer, public StructContainer, public ExtensionContainer {
    public:
        Brill::IR::ModuleName name;
        optional<unique_ptr<Module>> parent;

        explicit Module(const string &n) : name(move(n)), parent() {};

        explicit Module(unique_ptr<Module> p, const string& n) : name(p->name, move(n)), parent(make_optional(p)) {}

    public:
        list<Brill::IR::ImportDeclaration> imports;
    };
}
