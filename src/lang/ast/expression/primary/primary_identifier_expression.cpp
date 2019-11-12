
#include "primary_identifier_expression.h"

#include "llvm/IR/ValueSymbolTable.h"
#include <memory>

#include "illegal_state_exception.h"
#include "lang/ast/abstract/codegen_context.h"
#include "lang/ast/symbol_table.h"
#include "lang/ast/function/function.h"
#include "lang/ast/named_node.h"
#include "lang/ast/value_wrapper.h"

#include "util.h"

using namespace Brill::AST;

PrimaryIdentifierExpression::PrimaryIdentifierExpression(const std::shared_ptr<SymbolTable> &st, std::string i) : PrimaryExpression(st), identifier(std::move(i)) {}

llvm::Value *PrimaryIdentifierExpression::codegen(std::shared_ptr<CodegenContext> ctx) const {
    std::shared_ptr<NamedNode> node = this->getSymbolTable()->findFirst(this->identifier);

    if (std::shared_ptr<ValueWrapper> value = std::dynamic_pointer_cast<ValueWrapper>(node)) {
        return value->codegen(ctx);
    }
    if (llvm::Function *function = ctx->module->getFunction(this->identifier)) {
        return function;
    }
    if (node) {
        return node->codegen(ctx);
    }
    
    throw IllegalStateException("Could not find " + this->identifier + " in the symbol table");
}
