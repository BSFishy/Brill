
#pragma once

#include <string>
#include <memory>

#include "BrillParser.h"

#include "literal.h"

namespace Brill::AST {
    class StringLiteral : public Literal {
    public:
        std::string value;

        explicit StringLiteral(const std::shared_ptr<SymbolTable> &st, std::string v) : Literal(st), value(std::move(v)) {}

        llvm::Value *codegen(std::shared_ptr<CodegenContext>) override;
    };
}
