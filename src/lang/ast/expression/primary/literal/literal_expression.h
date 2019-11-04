
#pragma once

#include <memory>

#include "BrillParser.h"

#include "lang/ast/expression/primary/primary_expression.h"

namespace Brill::AST {
    class LiteralExpression : public PrimaryExpression {
    public:
        explicit LiteralExpression(const std::shared_ptr<SymbolTable> &st) : PrimaryExpression(st) {}

        llvm::Value *codegen(std::shared_ptr<CodegenContext>) override = 0;
    };

    std::shared_ptr<LiteralExpression> convert(const std::shared_ptr<ConvertContext>&, BrillParser::LiteralExpressionContext*);
}
