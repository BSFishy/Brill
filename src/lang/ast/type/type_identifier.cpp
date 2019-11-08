
#include "type_identifier.h"

#include "lang/ast/abstract/convert_context.h"
#include "lang/ast/abstract/codegen_context.h"

#include "util.h"

using namespace Brill::AST;

TypeIdentifier::TypeIdentifier(const std::shared_ptr<SymbolTable> &st, std::string i) : Type(st), identifier(std::move(i)) {}

llvm::Type *TypeIdentifier::getType(std::shared_ptr<CodegenContext> ctx) const {
    if (this->identifier == "i8") {
        return ctx->builder->getInt8PtrTy();
    } else {
        throw IllegalStateException("Unknown type: " + this->identifier);
    }
}

std::shared_ptr<TypeIdentifier> Brill::AST::convert(const std::shared_ptr<ConvertContext> &cctx, BrillParser::TypeIdentifierContext *ctx) {
    if (BrillParser::GenericArgumentClauseContext *genericContext = ctx->genericArgumentClause()) {
        cctx->error(genericContext->getStart(), "Generic argument types are not implemented");
        return nullptr;
    }
    if (BrillParser::TypeIdentifierContext *childContext = ctx->typeIdentifier()) {
        cctx->error(childContext->getStart(), "Referencing nested types is not implemented");
        return nullptr;
    }

    std::string identifier = ctx->typeName()->getText();
    return std::make_shared<TypeIdentifier>(cctx->parent->getSymbolTable(), identifier);
}
