
#include "argument.h"

using namespace Brill::IR;

std::shared_ptr<Argument> Convert::convert(BrillParser::ParameterContext *ctx) {
    return std::make_shared<Argument>(ctx->localParameterName()->getText(), ctx->typeAnnotation()->type()->getText());
}
