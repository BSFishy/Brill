
#include "top_level.h"
#include <iostream>

#include "tree/modules.h"
#include "convert/function/function.h"

#include "util.h"

using namespace Brill::IR;

void Brill::convert(BrillParser::TopLevelContext *context) {
    std::shared_ptr<IR::Module> module = Brill::getOrCreateModule("test");

    for(BrillParser::DeclarationContext *declaration : context->declarations()->declaration()) {
        if (BrillParser::FunctionDeclarationContext *functionContext = declaration->functionDeclaration()) {
            std::shared_ptr<Function> function = Convert::convert(functionContext);
            module->addFunction(function);
        } else {
            throw NotImplementedException();
        }
    }
}
