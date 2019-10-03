
#pragma once

#include <memory>

#include "tree/expression/literal/literal.h"

#include "literal_expression.h"

namespace Brill::IR {
    class LiteralLiteralExpression : public LiteralExpression {
    public:
        std::shared_ptr<Literal> literal;

        explicit LiteralLiteralExpression(std::shared_ptr<Literal> &l) : literal(l) {}

        llvm::Value *codegen(std::shared_ptr<CodegenContext>) override;
    };
}
