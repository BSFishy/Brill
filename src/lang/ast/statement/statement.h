
#pragma once

#include "lang/ast/node.h"

namespace Brill::AST {
    class Statement : public Node {
    public:
        llvm::Value *codegen(std::shared_ptr<CodegenContext>) override = 0;
    };
}
