
#pragma once

#include <memory>

#include "BrillParser.h"

#include "lang/ast/type/type.h"

namespace Brill::AST {
    class TypeAnnotation;

    class Parameter : public Type {
        std::string localname;
        std::shared_ptr<TypeAnnotation> typeAnnotation;
    public:
        Parameter(const std::shared_ptr<SymbolTable>&, std::string, const std::shared_ptr<TypeAnnotation>&);

        llvm::Type *getType(std::shared_ptr<CodegenContext>) const override;

        std::string getLocalname() const;
    };

    std::shared_ptr<Parameter> convert(const std::shared_ptr<ConvertContext>&, BrillParser::ParameterContext*);
}
