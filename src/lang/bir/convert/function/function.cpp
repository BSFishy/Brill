
#include "function.h"
#include <iostream>

using namespace Brill::IR;

std::shared_ptr<CodegenContext> Brill::IR::Convert::convert(std::shared_ptr<CodegenContext> ctx, Brill::BrillParser::FunctionDeclarationContext *context) {
    printf("function name: %s\n", context->functionName()->Identifier()->getText().c_str());

    return ctx;
}
