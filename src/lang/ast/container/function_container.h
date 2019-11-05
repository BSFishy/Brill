
#pragma once

#include <string>
#include <vector>

#include "container.h"

namespace Brill::AST {
    class Function;

    class FunctionContainer : public virtual Container {
        std::vector<std::shared_ptr<Function>> functions;
    public:
        void addFunction(const std::shared_ptr<Function>&);
        bool removeFunction(const std::shared_ptr<Function>&);
        std::shared_ptr<Function> getFunction(const std::string&) const;

        std::vector<std::shared_ptr<Function>> getFunctions() const;
        void codegenFunctions(const std::shared_ptr<CodegenContext>&) const;
    };
}
