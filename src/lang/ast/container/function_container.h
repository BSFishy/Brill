
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

        void addFunction(const std::shared_ptr<Function>&);
        bool removeFunction(const std::shared_ptr<Function>&);
        std::shared_ptr<Function> getFunction(const std::string&);

        void codegenFunctions(const std::shared_ptr<CodegenContext>&);
    };
}
