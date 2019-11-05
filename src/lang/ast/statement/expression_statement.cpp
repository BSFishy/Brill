
#include "expression_statement.h"

using namespace Brill::AST;

ExpressionStatement::ExpressionStatement(const std::shared_ptr<SymbolTable> &st, const std::shared_ptr<Expression> &e) : Statement(st) {
    expression = e;
}

llvm::Value *ExpressionStatement::codegen(std::shared_ptr<CodegenContext> ctx) const {
    return this->expression->codegen(ctx);
}
