
#pragma once

#include <string>

#include "code_generator.h"

namespace Brill::IR {
    class NamedCodeGenerator : public CodeGenerator {
    public:
        std::string name;

        explicit NamedCodeGenerator(std::string n) : name(std::move(n)) {}

        llvm::Value *codegen(std::shared_ptr<CodegenContext>) override = 0;
    };
}
