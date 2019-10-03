
#include "literal_literal_expression.h"

using namespace Brill::IR;

llvm::Value *LiteralLiteralExpression::codegen(std::shared_ptr<CodegenContext> ctx) {
    return this->literal->codegen(ctx);
}
