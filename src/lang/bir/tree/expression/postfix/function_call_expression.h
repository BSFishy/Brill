
#pragma once

#include <string>
#include <list>
#include <memory>

#include "llvm/IR/Value.h"

#include "tree/expression/expression.h"
#include "postfix_expression.h"

namespace Brill::IR {
    class FunctionCallExpression : public PostfixExpression {
    public:
        std::string name;
        std::list<std::shared_ptr<Expression>> arguments;

        explicit FunctionCallExpression(std::string n) : name(std::move(n)), arguments() {}

        llvm::Value *codegen(std::shared_ptr<CodegenContext>) override;
    };
}
