
#pragma once

#include <string>
#include <utility>

#include "bir.h"

namespace Brill {
    namespace IR {
        class ModuleName;

        class ImportDeclaration : public Declaration {
            Brill::IR::ModuleName moduleName;

            explicit ImportDeclaration(std::string name) : moduleName(std::move(name)) {} ;

            llvm::Value* codegen() override;
        };
    }
}
