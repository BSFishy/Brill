
#pragma once

#include <string>
#include <memory>
#include <utility>

#include "node.h"

namespace Brill::AST {
    /**
     * A node in the AST that has a name. This is any value that can be recognized by a string representing
     * its name. Examples of this include a class or function.
     */
    class NamedNode : public virtual Node {
        std::string name;
    public:
        NamedNode() = delete;
        explicit NamedNode(std::string);

        /**
         * Get the name of this node.
         */
        std::string getName() const;

        llvm::Value *codegen(std::shared_ptr<CodegenContext>) const override = 0;
    };
}
