
#pragma once

#include <memory>

#include "BrillParser.h"

#include "lang/ast/abstract/convert_context.h"
#include "lang/ast/node.h"

namespace Brill::AST {
    class PostfixBaseExpression;
    class PostfixFunctionExpression;
    class PostfixPostExpression;

    class PostfixExpression : public Node {
    public:
        std::shared_ptr<PostfixBaseExpression> baseExpression;
        std::shared_ptr<PostfixFunctionExpression> functionExpression;
        std::shared_ptr<PostfixPostExpression> postExpression;

        PostfixExpression() = delete;
        PostfixExpression(std::shared_ptr<PostfixBaseExpression> be, std::shared_ptr<PostfixFunctionExpression> fe = nullptr, std::shared_ptr<PostfixPostExpression> pe = nullptr) {
            baseExpression = be;
            functionExpression = fe;
            postExpression = pe;
        }

        llvm::Value *codegen(std::shared_ptr<CodegenContext>) override;
    };

    std::shared_ptr<PostfixExpression> convert(std::shared_ptr<ConvertContext>, BrillParser::PostfixExpressionContext*);
}
