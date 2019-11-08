
#pragma once

#include <memory>

#include "llvm/IR/Type.h"

#include "BrillParser.h"

#include "lang/ast/node.h"

namespace Brill::AST {
    class Type : public Node {
    public:
        explicit Type(const std::shared_ptr<SymbolTable>&);

        virtual llvm::Type *getType(std::shared_ptr<CodegenContext>) const = 0;
        llvm::Value *codegen(std::shared_ptr<CodegenContext>) const override;
    };

    std::shared_ptr<Type> convert(const std::shared_ptr<ConvertContext>&, BrillParser::TypeContext*);
}
