
#pragma once

#include <string>
#include <memory>
#include <utility>

#include "node.h"

namespace Brill::AST {
    static const std::string MANGLER_PREFIX = "$b_";

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
        virtual std::string getName() const;

        virtual std::string getMangledName() const = 0;

        llvm::Value *codegen(std::shared_ptr<CodegenContext>) const override = 0;
    };
}
