
#pragma once

#include <string>
#include <memory>

namespace Brill::AST {
    class Node;

    struct ConvertContext {
        std::string moduleName;
        std::shared_ptr<Node> parent;

        explicit ConvertContext(std::string);
        ConvertContext(std::string, const std::shared_ptr<Node>&);

        std::shared_ptr<ConvertContext> withParent(const std::shared_ptr<Node>&) const;
    };
}
