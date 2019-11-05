
#pragma once

#include <string>
#include <memory>
#include <vector>

#include "BrillParser.h"

#include "named_node.h"
#include "container/function_container.h"

namespace Brill::AST {
    class Module : public NamedNode, public FunctionContainer {
        std::shared_ptr<Module> parent;
    public:
        Module() = delete;
        explicit Module(const std::string&);
        Module(const std::string&, const std::shared_ptr<Module>&);

        std::shared_ptr<Module> getParent() const;

        llvm::Value *codegen(std::shared_ptr<CodegenContext>) const override;
        std::shared_ptr<Brill::AST::CodegenContext> codegen() const;
    };

    std::shared_ptr<Module> convert(const std::shared_ptr<ConvertContext>&, BrillParser::TopLevelContext*);

    void addModule(const std::shared_ptr<Module>&);
    std::shared_ptr<Module> getModule(const std::string&);
    std::shared_ptr<Module> getOrCreateModule(const std::string&);
    bool removeModule(const std::string&);
}
