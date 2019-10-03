
#include "identifier_expression.h"

using namespace Brill::IR;

std::string IdentifierExpression::valuegen(std::shared_ptr<CodegenContext> ctx) {
    return this->value;
}
