
#pragma once

#include <memory>

#include "BrillParser.h"

#include "lang/ast/node.h"

namespace Brill::AST {
    class PrefixExpression;

    class Expression : public Node {
        std::shared_ptr<PrefixExpression> prefixExpression;
    public:
        Expression(const std::shared_ptr<SymbolTable>&, const std::shared_ptr<PrefixExpression>&);

        llvm::Value *codegen(std::shared_ptr<CodegenContext>) const override;
    };

    std::shared_ptr<Expression> convert(const std::shared_ptr<ConvertContext>&, BrillParser::ExpressionContext*);
}
