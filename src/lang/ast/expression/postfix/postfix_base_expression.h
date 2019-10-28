
#pragma once

#include <memory>

#include "BrillParser.h"

#include "lang/ast/abstract/convert_context.h"
#include "lang/ast/node.h"

namespace Brill::AST {
    class PrimaryExpression;
    class PostfixDotExpression;

    class PostfixBaseExpression : public Node {
    public:
        std::shared_ptr<PrimaryExpression> primaryExpression;
        std::shared_ptr<PostfixDotExpression> dotExpression;

        PostfixBaseExpression() = delete;
        PostfixBaseExpression(std::shared_ptr<PrimaryExpression> pe, std::shared_ptr<PostfixDotExpression> de = nullptr) {
            primaryExpression = pe;
            dotExpression = de;
        }

        llvm::Value *codegen(std::shared_ptr<CodegenContext>) override;
    };

    std::shared_ptr<PostfixBaseExpression> convert(std::shared_ptr<ConvertContext>, BrillParser::PostfixBaseExpressionContext*);
}
