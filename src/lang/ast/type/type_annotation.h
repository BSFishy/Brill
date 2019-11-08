
#pragma once

#include <memory>

#include "BrillParser.h"

namespace Brill::AST {
    class Type;
    class ConvertContext;

    class TypeAnnotation {
        std::shared_ptr<Type> type;
        bool inout;
    public:
        TypeAnnotation(const std::shared_ptr<Type>&, bool = false);

        std::shared_ptr<Type> getType() const;
        bool isInout() const;
    };

    std::shared_ptr<TypeAnnotation> convert(const std::shared_ptr<ConvertContext>&, BrillParser::TypeAnnotationContext*);
}
