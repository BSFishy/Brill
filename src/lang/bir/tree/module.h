
#pragma once

#include <list>
#include <string>
#include <utility>
#include <lang/bir/tree/variable/declaration/variable_declaration.h>

#include "bir.h"

using namespace std;

namespace Brill {
    namespace IR {
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
        class Module {
        public:
            Brill::IR::ModuleName name;

            explicit Module(std::string n) : name(std::move(n)) {} ;
        public:
            list<Brill::IR::ImportDeclaration> imports;

            list<Brill::IR::Variable> variables;
            list<Brill::IR::Function> functions;

            list<Brill::IR::Protocol> protocols;
            list<Brill::IR::Class> classes;
            list<Brill::IR::Enum> enums;
            list<Brill::IR::Struct> structs;
            list<Brill::IR::Extension> extensions;
        };
    }
}
