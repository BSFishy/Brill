
#pragma once

#include <memory>

#include "BrillParser.h"

#include "lang/ast/node.h"

namespace Brill::AST {
    class Statement : public Node {
    public:
        explicit Statement(const std::shared_ptr<SymbolTable> &st);
        // explicit Statement(const std::shared_ptr<SymbolTable> &st) : Node(st) {}

        llvm::Value *codegen(std::shared_ptr<CodegenContext>) const override = 0;
    };

    std::shared_ptr<Statement> convert(const std::shared_ptr<ConvertContext>&, BrillParser::StatementContext*);
}
