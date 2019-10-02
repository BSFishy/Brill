
#pragma once

#include <string>
#include <utility>

#include "tree/declarations/declaration.h"

namespace Brill::IR {
    class ModuleName;

    class ImportDeclaration : public Declaration {
        std::string moduleName;

        explicit ImportDeclaration(std::string &name) : moduleName(std::move(name)) {};

        llvm::Value *codegen(std::shared_ptr<CodegenContext>) override;
    };
}
