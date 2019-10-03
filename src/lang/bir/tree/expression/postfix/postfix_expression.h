
#pragma once

#include <string>

#include "llvm/IR/Value.h"

#include "tree/abstract/codegen/code_generator.h"

namespace Brill::IR {
    class PostfixExpression : public CodeGenerator {
    public:
        llvm::Value *codegen(std::shared_ptr<CodegenContext>) override = 0;
    };
}
