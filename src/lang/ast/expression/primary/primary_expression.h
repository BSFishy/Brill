
#pragma once

#include <memory>

#include "BrillParser.h"

#include "lang/ast/abstract/convert_context.h"
#include "lang/ast/node.h"

namespace Brill::AST {
    class PrimaryExpression : public virtual Node {
    public:
        llvm::Value *codegen(std::shared_ptr<CodegenContext>) override = 0;
    };

    std::shared_ptr<PrimaryExpression> convert(std::shared_ptr<ConvertContext>, BrillParser::PrimaryExpressionContext*);
}
