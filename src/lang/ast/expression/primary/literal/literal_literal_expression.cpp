
#include "literal_literal_expression.h"

#include "lang/ast/literal/literal.h"

using namespace Brill::AST;

llvm::Value *LiteralLiteralExpression::codegen(std::shared_ptr<CodegenContext> ctx) {
    return this->literal->codegen(ctx);
}
