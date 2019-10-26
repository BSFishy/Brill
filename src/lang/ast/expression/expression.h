
#pragma once

#include <memory>

#include "BrillParser.h"

#include "lang/ast/node.h"
#include "prefix_expression.h"

namespace Brill::AST {
    class Expression : public Node {
    public:
        std::shared_ptr<PrefixExpression> prefixExpression;

        explicit Expression(std::shared_ptr<PrefixExpression> pe) : prefixExpression(std::move(pe)) {}

        llvm::Value *codegen(std::shared_ptr<CodegenContext>) override = 0;
    };

    std::shared_ptr<Expression> convert(std::shared_ptr<ConvertContext>, BrillParser::ExpressionContext*);
}
