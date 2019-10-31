
#pragma once

#include <string>
#include <memory>
#include <vector>

#include "BrillParser.h"

#include "named_node.h"
#include "symbol_table.h"

#include "abstract/convert_context.h"
#include "container/function_container.h"

namespace Brill::AST {
    class Module : public NamedNode, public FunctionContainer {
    public:
        std::shared_ptr<Module> parent;

        Module() = delete;
        explicit Module(std::string n) : NamedNode(n) {}
        explicit Module(std::string n, std::shared_ptr<Module> const& p) : NamedNode(n, p->symbolTable->child()) {
            parent = p;
        }

        llvm::Value *codegen(std::shared_ptr<CodegenContext>) override;
        std::shared_ptr<Brill::AST::CodegenContext> codegen();
    };

    std::shared_ptr<Module> convert(std::shared_ptr<ConvertContext>, BrillParser::TopLevelContext *);

    static std::vector<std::shared_ptr<Module>> modules;

    void addModule(const std::shared_ptr<Module>&);
    std::shared_ptr<Module> getModule(const std::string&);
    std::shared_ptr<Module> getOrCreateModule(const std::string&);
    bool removeModule(const std::string&);
}
