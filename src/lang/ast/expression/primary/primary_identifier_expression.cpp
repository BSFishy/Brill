
#include "primary_identifier_expression.h"

#include "lang/ast/function/function.h"
#include "lang/ast/named_node.h"

#include "util.h"

using namespace Brill::AST;

llvm::Value *PrimaryIdentifierExpression::codegen(std::shared_ptr<CodegenContext> ctx) {
    std::shared_ptr<NamedNode> node = this->lookup(this->identifier);
    if (!node) {
        throw IllegalStateException(this->identifier + " could not be found");
    }

    return node->codegen(ctx);
}

std::shared_ptr<NamedNode> PrimaryIdentifierExpression::lookup(std::string identifier) {
    return this->symbolTable->find(identifier);
}
