
#pragma once

#include "llvm/IR/Value.h"

#include "tree/abstract/codegen/code_generator.h"

namespace Brill::IR {
    class Statement : public CodeGenerator {
    public:
        llvm::Value *codegen(std::shared_ptr<CodegenContext>) override = 0;
    };
}
