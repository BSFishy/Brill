
#pragma once

#include <string>
#include <vector>

#include "container.h"
#include "lang/ast/abstract/codegen_context.h"

namespace Brill::AST {
    class Function;

    class FunctionContainer : public virtual Container {
    public:
        std::vector<Function*> functions;

        void addFunction(Function*);
        bool removeFunction(Function*);
        Function *getFunction(std::string);

        void codegenFunctions(std::shared_ptr<CodegenContext>);
    };
}
