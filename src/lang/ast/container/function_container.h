
#pragma once

#include <string>
#include <vector>

#include "container.h"
#include "lang/ast/abstract/codegen_context.h"

namespace Brill::AST {
    class Function;

    class FunctionContainer : public virtual Container {
    public:
        std::vector<std::shared_ptr<Function>> functions;

        void addFunction(std::shared_ptr<Function>);
        bool removeFunction(std::shared_ptr<Function>);
        std::shared_ptr<Function> getFunction(std::string);

        void codegenFunctions(std::shared_ptr<CodegenContext>);
    };
}
