
#pragma once

#include <memory>

#include "BrillParser.h"

#include "lang/ast/node.h"

namespace Brill::AST {
    class PrimaryExpression : public Node {
    public:
        explicit PrimaryExpression(const std::shared_ptr<SymbolTable>&);

        llvm::Value *codegen(std::shared_ptr<CodegenContext>) const override = 0;
    };

    std::shared_ptr<PrimaryExpression> convert(const std::shared_ptr<ConvertContext>&, BrillParser::PrimaryExpressionContext*);
}
