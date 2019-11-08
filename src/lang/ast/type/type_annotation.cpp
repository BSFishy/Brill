
#include "type_annotation.h"

#include "type.h"
#include "lang/ast/abstract/convert_context.h"

using namespace Brill::AST;

TypeAnnotation::TypeAnnotation(const std::shared_ptr<Type> &t, bool i) : inout(i) {
    this->type = t;
}

std::shared_ptr<Type> TypeAnnotation::getType() const {
    return this->type;
}

bool TypeAnnotation::isInout() const {
    return this->inout;
}

std::shared_ptr<TypeAnnotation> Brill::AST::convert(const std::shared_ptr<ConvertContext> &cctx, BrillParser::TypeAnnotationContext *ctx) {
    if (BrillParser::AttributesContext *attributesContext = ctx->attributes()) {
        cctx->error(attributesContext->getStart(), "Type annotation attributes are not implemented");
        return nullptr;
    }

    std::shared_ptr<Type> type = convert(cctx, ctx->type());
    if (!type) {
        return nullptr;
    }

    return std::make_shared<TypeAnnotation>(type, ctx->INOUT() != nullptr);
}
