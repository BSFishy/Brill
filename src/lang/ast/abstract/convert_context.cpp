
#include "convert_context.h"

using namespace Brill::AST;

ConvertContext::ConvertContext(std::string mn) : moduleName(mn) {}
ConvertContext::ConvertContext(std::string mn, const std::shared_ptr<Node> &p) : moduleName(mn) {
    this->parent = p;
}

std::shared_ptr<ConvertContext> ConvertContext::withParent(const std::shared_ptr<Node> &p) const {
    return std::make_shared<ConvertContext>(this->moduleName, p);
}
