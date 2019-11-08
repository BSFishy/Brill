
#include "type.h"

#include "lang/ast/abstract/convert_context.h"

#include "type_identifier.h"

#include "util.h"

using namespace Brill::AST;

Type::Type(const std::shared_ptr<SymbolTable> &st) : Node(st) { }

llvm::Value *Type::codegen(std::shared_ptr<CodegenContext> ctx) const {
    throw IllegalStateException("Tried to codegen a type");
}

std::shared_ptr<Type> Brill::AST::convert(const std::shared_ptr<ConvertContext> &cctx, BrillParser::TypeContext *ctx) {
    if (BrillParser::TypeIdentifierTypeContext *identifierContext = dynamic_cast<BrillParser::TypeIdentifierTypeContext*>(ctx)) {
        return convert(cctx, identifierContext->typeIdentifier());
    } else {
        cctx->error(ctx->getStart(), "Not implemented");
        return nullptr;
    }
}
