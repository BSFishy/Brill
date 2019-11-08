
#pragma once

#include <memory>

#include "BrillParser.h"

#include "lang/ast/node.h"

namespace Brill::AST  {
    class Expression;

    class FunctionCallArgument : public Node {
        std::shared_ptr<Expression> expression;
    public:
        FunctionCallArgument(const std::shared_ptr<SymbolTable>&, const std::shared_ptr<Expression>&);

        llvm::Value *codegen(std::shared_ptr<CodegenContext>) const override;
    };

    std::shared_ptr<FunctionCallArgument> convert(const std::shared_ptr<ConvertContext>&, BrillParser::FunctionCallArgumentContext*);
}
