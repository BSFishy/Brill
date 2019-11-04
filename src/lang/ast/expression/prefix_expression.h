
#pragma once

#include <memory>

#include "BrillParser.h"

#include "lang/ast/abstract/convert_context.h"
#include "lang/ast/node.h"
#include "postfix/postfix_expression.h"

namespace Brill::AST {
    class PrefixExpression : public Node {
    public:
        std::shared_ptr<PostfixExpression> postfixExpression;

        explicit PrefixExpression(const std::shared_ptr<SymbolTable> &st, const std::shared_ptr<PostfixExpression> &pe) : Node(st) {
            postfixExpression = pe;
        }

        llvm::Value *codegen(std::shared_ptr<CodegenContext>) override;
    };

    std::shared_ptr<PrefixExpression> convert(const std::shared_ptr<ConvertContext>&, BrillParser::PrefixExpressionContext*);
}
