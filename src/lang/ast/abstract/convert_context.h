
#pragma once

#include <string>
#include <memory>

namespace Brill::AST {
    class Node;

    struct ConvertContext {
        std::string moduleName;
        std::shared_ptr<Node> parent;

        explicit ConvertContext(std::string mn) : moduleName(std::move(mn)) {}
        ConvertContext(std::string mn, std::shared_ptr<Node> const& p) : moduleName(std::move(mn)) {
            parent = p;
        }

        std::shared_ptr<ConvertContext> withParent(std::shared_ptr<Node> p) {
            return std::make_shared<ConvertContext>(this->moduleName, p);
        }
    };
}
