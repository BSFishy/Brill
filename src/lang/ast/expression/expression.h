
#pragma once

#include <memory>

#include "BrillParser.h"

#include "lang/ast/node.h"
#include "prefix_expression.h"

namespace Brill::AST {
    class Expression : public Node {
    public:
        std::shared_ptr<PrefixExpression> prefixExpression;

        explicit Expression(const std::shared_ptr<PrefixExpression> &pe) {
            prefixExpression = pe;
        }

        llvm::Value *codegen(std::shared_ptr<CodegenContext>) override;
    };

    std::shared_ptr<Expression> convert(const std::shared_ptr<ConvertContext>&, BrillParser::ExpressionContext*);
}
