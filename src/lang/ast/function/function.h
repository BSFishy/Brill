
#pragma once

#include <string>
#include <memory>
#include <vector>

#include "BrillParser.h"

#include "lang/ast/named_node.h"
#include "lang/ast/container/statement_container.h"

namespace Brill::AST {
    class Parameter;

    class Function : public NamedNode, public StatementContainer {
        std::shared_ptr<Node> parent;

        std::vector<std::shared_ptr<Parameter>> parameters;
        bool varargs;

        bool generated = false;
    public:
        Function() = delete;
        Function(std::string, const std::shared_ptr<Node>&, bool = false);

        llvm::Value *codegen(std::shared_ptr<CodegenContext>) const override;

        void setVarargs(bool);
        void addParameter(std::shared_ptr<Parameter>);
    };

    std::shared_ptr<Function> convert(const std::shared_ptr<ConvertContext>&, BrillParser::FunctionDeclarationContext*);
}
