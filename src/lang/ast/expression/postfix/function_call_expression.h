
#pragma once

#include <memory>

#include "postfix_expression.h"

namespace Brill::AST {
    class FunctionCallExpression : public PostfixExpression {
        std::shared_ptr<PostfixExpression> postfixExpression;
    public:
        FunctionCallExpression(const std::shared_ptr<SymbolTable>&, const std::shared_ptr<PostfixExpression>&);

        llvm::Value *codegen(std::shared_ptr<CodegenContext>) const override;
    };

    std::shared_ptr<FunctionCallExpression> convert(const std::shared_ptr<ConvertContext>&, BrillParser::FunctionCallExpressionContext*);
}
