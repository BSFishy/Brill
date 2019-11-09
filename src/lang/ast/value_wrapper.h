
#pragma once

#include "named_node.h"

namespace Brill::AST {
    class ValueWrapper : public NamedNode {
        llvm::Value *value;
    public:
        ValueWrapper(const std::shared_ptr<SymbolTable>&, llvm::Value*);
        ~ValueWrapper();

        std::string getName() const override;
        llvm::Value *codegen(std::shared_ptr<CodegenContext>) const override;
    };
}
