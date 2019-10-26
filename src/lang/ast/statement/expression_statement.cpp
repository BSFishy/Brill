
#include "expression_statement.h"

using namespace Brill::AST;

llvm::Value *ExpressionStatement::codegen(std::shared_ptr<CodegenContext> ctx) {
    return this->expression->codegen(ctx);
}
