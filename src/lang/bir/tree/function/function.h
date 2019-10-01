
#pragma once

#include <list>
#include <string>
#include <memory>

#include "tree/container/statement_container.h"

namespace Brill::IR {
    class Module;
    class Class;
    class Statement;

    class Function {
    public:
        std::string name;
        std::shared_ptr<Module> module;
        std::shared_ptr<Class> parentClass;

        std::list<std::unique_ptr<Statement>> statements;

        explicit Function(std::shared_ptr<Module> m, std::string n) : module(m), name(std::move(n)), parentClass(nullptr) {}
        explicit Function(std::shared_ptr<Module> m, std::string n, std::shared_ptr<Class> p) : module(m), name(std::move(n)), parentClass(p) {}

        void addStatement(std::unique_ptr<Statement> s);
    };
}
