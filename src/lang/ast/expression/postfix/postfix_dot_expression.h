
#pragma once

#include <memory>

#include "BrillParser.h"

#include "lang/ast/abstract/convert_context.h"
#include "lang/ast/node.h"

namespace Brill::AST {
    class PostfixDotExpression : public Node {
    public:
        llvm::Value *codegen(std::shared_ptr<CodegenContext>) override;
    };

    std::shared_ptr<PostfixDotExpression> convert(std::shared_ptr<ConvertContext>, BrillParser::PostfixDotExpressionContext*);
}
