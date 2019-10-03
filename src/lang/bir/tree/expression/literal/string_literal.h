
#pragma once

#include <string>

#include "literal.h"

namespace Brill::IR {
    class StringLiteral : public Literal {
    public:
        std::string value;
        
        explicit StringLiteral(std::string v) : value(std::move(v)) {}
        
        llvm::Value *codegen(std::shared_ptr<CodegenContext>) override;
    };
}
