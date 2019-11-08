
#pragma once

#include <memory>

#include "BrillParser.h"

#include "lang/ast/node.h"

namespace Brill::AST {
    class PostfixExpression : public Node {
    public:
        explicit PostfixExpression(const std::shared_ptr<SymbolTable>&);

        llvm::Value *codegen(std::shared_ptr<CodegenContext>) const override = 0;
    };

    std::shared_ptr<PostfixExpression> convert(const std::shared_ptr<ConvertContext>&, BrillParser::PostfixExpressionContext*);
}
