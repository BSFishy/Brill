
#pragma once

#include <memory>

#include "llvm/IR/Value.h"

#include "tree/abstract/codegen/code_generator.h"
#include "prefix_expression.h"

namespace Brill::IR {
    class Expression : public CodeGenerator {
    public:
        std::shared_ptr<PrefixExpression> prefixExpression;
        
        explicit Expression(std::shared_ptr<PrefixExpression> &e) : prefixExpression(e) {}
        
        llvm::Value *codegen(std::shared_ptr<CodegenContext>) override;
    };
}
