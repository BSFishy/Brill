
#pragma once

#include <string>
#include <memory>

namespace Brill::AST {
    class Node;

    struct ConvertContext {
        std::string moduleName;
        Node *parent;

        explicit ConvertContext(std::string mn) : moduleName(mn) {}
        ConvertContext(std::string mn, Node *p) : moduleName(mn), parent(p) {}

        std::shared_ptr<ConvertContext> withParent(Node *p) {
            return std::make_shared<ConvertContext>(this->moduleName, p);
        }
    };
}
