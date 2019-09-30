
#pragma once

#include <string>
#include <utility>

#include "bir.h"

namespace Brill::IR {
    class ModuleName;

    class ImportDeclaration : public Declaration {
        std::string moduleName;

        explicit ImportDeclaration(const std::string &name) : moduleName(std::move(name)) {};

        llvm::Value *codegen() override;
    };
}
