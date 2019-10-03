
#include "expression_statement.h"

using namespace Brill::IR;

llvm::Value *ExpressionStatement::codegen(std::shared_ptr<CodegenContext> ctx) {
    return this->expression->codegen(ctx);
}
