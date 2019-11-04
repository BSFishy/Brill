
#pragma once

#include <memory>

#include "postfix_expression.h"

namespace Brill::AST {
    class FunctionCallExpression : public PostfixExpression {
    public:
        std::shared_ptr<PostfixExpression> postfixExpression;

        explicit FunctionCallExpression(const std::shared_ptr<SymbolTable> &st, const std::shared_ptr<PostfixExpression> &pe) : PostfixExpression(st) {
            postfixExpression = pe;
        }

        llvm::Value *codegen(std::shared_ptr<CodegenContext>) override;
    };

    std::shared_ptr<FunctionCallExpression> convert(const std::shared_ptr<ConvertContext>&, BrillParser::FunctionCallExpressionContext*);
}
