
#pragma once

#include <memory>

#include "BrillParser.h"

#include "lang/ast/node.h"

namespace Brill::AST {
    class Literal : public virtual Node {
    public:
        explicit Literal(const std::shared_ptr<SymbolTable>&);

        llvm::Value *codegen(std::shared_ptr<CodegenContext>) const override = 0;
    };

    std::shared_ptr<Literal> convert(const std::shared_ptr<ConvertContext>&, BrillParser::LiteralContext*);
}
