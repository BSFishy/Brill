
#include "primary_identifier_expression.h"

#include "lang/ast/symbol_table.h"
#include "lang/ast/function/function.h"
#include "lang/ast/named_node.h"

#include "util.h"

using namespace Brill::AST;

PrimaryIdentifierExpression::PrimaryIdentifierExpression(const std::shared_ptr<SymbolTable> &st, std::string i) : PrimaryExpression(st), identifier(std::move(i)) {}

llvm::Value *PrimaryIdentifierExpression::codegen(std::shared_ptr<CodegenContext> ctx) const {
    std::shared_ptr<NamedNode> node = this->lookup(this->identifier);
    if (!node) {
        throw IllegalStateException(this->identifier + " could not be found");
    }

    return node->codegen(ctx);
}

std::shared_ptr<NamedNode> PrimaryIdentifierExpression::lookup(std::string identifier) const {
    return this->getSymbolTable()->findFirst(identifier);
}
