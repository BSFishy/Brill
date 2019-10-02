
#include "function.h"
#include <iostream>

using namespace Brill::IR;

std::shared_ptr<CodegenContext> Brill::IR::Convert::convert(std::shared_ptr<CodegenContext> ctx, Brill::BrillParser::FunctionDeclarationContext *context) {
    printf("test\n");
    printf("here: %s\n", context->toStringTree().c_str());

    return ctx;
}
