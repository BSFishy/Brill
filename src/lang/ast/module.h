
#pragma once

#include <string>
#include <memory>

#include "BrillParser.h"

#include "named_node.h"
#include "symbol_table.h"

namespace Brill::AST {
    class Module : public NamedNode {
    public:
        std::shared_ptr<Module> parent;

        Module() = delete;
        explicit Module(std::string &n) : NamedNode(n), parent(nullptr) {}
        explicit Module(std::string &n, std::shared_ptr<Module> &p) : NamedNode(n, p->symbolTable->child()), parent(p) {}

        llvm::Value *codegen(std::shared_ptr<CodegenContext>) override;
        std::shared_ptr<Brill::AST::CodegenContext> codegen();
    };

    std::shared_ptr<Module> convert(BrillParser::TopLevelContext *);
}
