
#pragma once

#include <string>

#include "type.h"

namespace Brill::AST {
    class TypeIdentifier : public Type {
        std::string identifier;
    public:
        TypeIdentifier(const std::shared_ptr<SymbolTable>&, std::string);

        llvm::Type *getType(std::shared_ptr<CodegenContext>) const override;
    };

    std::shared_ptr<TypeIdentifier> convert(const std::shared_ptr<ConvertContext>&, BrillParser::TypeIdentifierContext*);
}
