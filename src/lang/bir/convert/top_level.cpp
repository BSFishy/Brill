
#include "top_level.h"
#include <iostream>

#include "convert/function/function.h"

#include "util.h"

using namespace Brill::IR;

std::shared_ptr<CodegenContext> Brill::convert(Brill::BrillParser::TopLevelContext *context) {
    std::shared_ptr<CodegenContext> ctx;
    printf("xd%s\n", context->toStringTree().c_str());

    for(Brill::BrillParser::DeclarationContext *declaration : context->declarations()->declaration()) {
        if (Brill::BrillParser::FunctionDeclarationContext *function = declaration->functionDeclaration()) {
            Convert::convert(ctx, function);
        } else {
            throw NotImplementedException();
        }
    }

    return ctx;
}
