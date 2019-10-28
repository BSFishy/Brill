
#pragma once

#include <memory>

#include "BrillParser.h"

#include "lang/ast/abstract/convert_context.h"
#include "lang/ast/node.h"

namespace Brill::AST {
    class PostfixFunctionExpression : public Node {
    public:
        PostfixFunctionExpression() = delete;

        llvm::Value *codegen(std::shared_ptr<CodegenContext>) override;
    };

    std::shared_ptr<PostfixFunctionExpression> convert(std::shared_ptr<ConvertContext>, BrillParser::PostfixFunctionExpressionContext*);
}
