
#include "parameter.h"

#include "lang/ast/abstract/convert_context.h"

#include "lang/ast/type/type_annotation.h"

using namespace Brill::AST;

Parameter::Parameter(const std::shared_ptr<SymbolTable> &st, std::string ln, const std::shared_ptr<TypeAnnotation> &ta) : Type(st), localname(std::move(ln)) {
    this->typeAnnotation = ta;
}

llvm::Type *Parameter::getType(std::shared_ptr<CodegenContext> ctx) const {
    return this->typeAnnotation->getType()->getType(ctx);
}

std::string Parameter::getLocalname() const {
    return this->localname;
}

std::shared_ptr<Parameter> Brill::AST::convert(const std::shared_ptr<ConvertContext> &cctx, BrillParser::ParameterContext *ctx) {
    if (BrillParser::ExternalParameterNameContext *externalNameContext = ctx->externalParameterName()) {
        cctx->error(externalNameContext->getStart(), "External parameter names are not implemented");
        return nullptr;
    }
    if (BrillParser::DefaultArgumentClauseContext *defaultContext = ctx->defaultArgumentClause()) {
        cctx->error(defaultContext->getStart(), "Default parameters are not implemented");
        return nullptr;
    }

    std::shared_ptr<TypeAnnotation> typeAnnotation = convert(cctx, ctx->typeAnnotation());
    if (!typeAnnotation) {
        return nullptr;
    }

    std::string localname = ctx->localParameterName()->getText();
    return std::make_shared<Parameter>(cctx->parent->getSymbolTable(), localname, typeAnnotation);
}
