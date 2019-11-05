
#include "literal_literal_expression.h"

#include "lang/ast/literal/literal.h"

using namespace Brill::AST;

LiteralLiteralExpression::LiteralLiteralExpression(const std::shared_ptr<SymbolTable> &st, const std::shared_ptr<Literal> &l) : LiteralExpression(st) {
    literal = l;
}

llvm::Value *LiteralLiteralExpression::codegen(std::shared_ptr<CodegenContext> ctx) const {
    return this->literal->codegen(ctx);
}
