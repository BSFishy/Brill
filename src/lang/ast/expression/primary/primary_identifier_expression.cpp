
#include "primary_identifier_expression.h"

#include "illegal_state_exception.h"
#include "lang/ast/abstract/codegen_context.h"
#include "lang/ast/symbol_table.h"
#include "lang/ast/function/function.h"
#include "lang/ast/named_node.h"

#include "util.h"

using namespace Brill::AST;

PrimaryIdentifierExpression::PrimaryIdentifierExpression(const std::shared_ptr<SymbolTable> &st, std::string i) : PrimaryExpression(st), identifier(std::move(i)) {}

llvm::Value *PrimaryIdentifierExpression::codegen(std::shared_ptr<CodegenContext> ctx) const {
    if (llvm::Function *function = ctx->module->getFunction(this->identifier)) {
        return function;
    }
    

    std::shared_ptr<NamedNode> node = this->getSymbolTable()->findFirst(this->identifier);
    if (!node) {
        throw IllegalStateException("Could not find " + this->identifier + " in the symbol table");
    }

    llvm::IRBuilderBase::InsertPoint ip = ctx->builder->saveAndClearIP();
    llvm::Value *value = node->codegen(ctx);
    ctx->builder->restoreIP(ip);

    return value;
}
