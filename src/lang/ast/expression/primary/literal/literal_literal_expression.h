
#pragma once

#include <memory>

#include "BrillParser.h"

#include "literal_expression.h"

namespace Brill::AST {
    class Literal;

    class LiteralLiteralExpression : public LiteralExpression {
    public:
        std::shared_ptr<Literal> literal;

        LiteralLiteralExpression() = delete;
        explicit LiteralLiteralExpression(std::shared_ptr<Literal> l) {
            literal = l;
        }

        llvm::Value *codegen(std::shared_ptr<CodegenContext>) override;
    };
}
