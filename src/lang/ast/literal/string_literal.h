
#pragma once

#include <string>
#include <memory>

#include "BrillParser.h"

#include "literal.h"

namespace Brill::AST {
    class StringLiteral : public Literal {
        std::string value;
    public:
        StringLiteral(const std::shared_ptr<SymbolTable>&, std::string);

        llvm::Value *codegen(std::shared_ptr<CodegenContext>) const override;
    };
}
