
#pragma once

#include <memory>
#include <vector>

#include "postfix_expression.h"

namespace Brill::AST {
    class FunctionCallArgument;

    class FunctionCallExpression : public PostfixExpression {
        std::shared_ptr<PostfixExpression> postfixExpression;

        std::vector<std::shared_ptr<FunctionCallArgument>> arguments;
    public:
        FunctionCallExpression(const std::shared_ptr<SymbolTable>&, const std::shared_ptr<PostfixExpression>&);

        llvm::Value *codegen(std::shared_ptr<CodegenContext>) const override;

        void addArgument(const std::shared_ptr<FunctionCallArgument>&);
    };

    std::shared_ptr<FunctionCallExpression> convert(const std::shared_ptr<ConvertContext>&, BrillParser::FunctionCallExpressionContext*);
}
