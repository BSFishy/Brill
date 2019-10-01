
#pragma once

#include <string>
#include <utility>

#include "tree/expression/expression.h"

namespace Brill::IR {
    class StringConstant : public Expression {
    public:
        std::string value;

        explicit StringConstant(std::string v) : value(std::move(v)) {}

        llvm::Value *codegen(std::shared_ptr<CodegenContext>) override;
    };
}
