
#pragma once

#include <memory>

#include "llvm/IR/Value.h"

#include "tree/abstract/codegen/code_generator.h"
#include "postfix/postfix_expression.h"

namespace Brill::IR {
    class PrefixExpression : public CodeGenerator {
    public:
        std::shared_ptr<PostfixExpression> postfixExpression;

        explicit PrefixExpression(std::shared_ptr<PostfixExpression> &e) : postfixExpression(e) {}

        llvm::Value *codegen(std::shared_ptr<CodegenContext>) override;
    };
}
