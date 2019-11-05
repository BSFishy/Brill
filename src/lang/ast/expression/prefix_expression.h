
#pragma once

#include <memory>

#include "BrillParser.h"

#include "lang/ast/node.h"

namespace Brill::AST {
    class PostfixExpression;

    class PrefixExpression : public Node {
        std::shared_ptr<PostfixExpression> postfixExpression;
    public:
        PrefixExpression(const std::shared_ptr<SymbolTable>&, const std::shared_ptr<PostfixExpression>&);

        llvm::Value *codegen(std::shared_ptr<CodegenContext>) const override;
    };

    std::shared_ptr<PrefixExpression> convert(const std::shared_ptr<ConvertContext>&, BrillParser::PrefixExpressionContext*);
}
