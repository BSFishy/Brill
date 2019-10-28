
#pragma once

#include <memory>

#include "BrillParser.h"

#include "lang/ast/node.h"

namespace Brill::AST {
    class PostfixPostExpression : public Node {
    public:
        llvm::Value *codegen(std::shared_ptr<CodegenContext>) override;
    };

    std::shared_ptr<PostfixPostExpression> convert(std::shared_ptr<ConvertContext>, BrillParser::PostfixPostExpressionContext*);
}
