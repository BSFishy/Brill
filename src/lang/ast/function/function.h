
#pragma once

#include <string>
#include <memory>

#include "BrillParser.h"

#include "lang/ast/node.h"
#include "lang/ast/named_node.h"
#include "lang/ast/symbol_table.h"

#include "abstract/convert_context.h"
#include "lang/ast/container/statement_container.h"

namespace Brill::AST {
    class Function : public NamedNode, public StatementContainer {
    public:
        Node *parent;

        Function() = delete;
        explicit Function(std::string &n, Node* const& p) : NamedNode(n, p->symbolTable->child()) {
            parent = p;
        }

        llvm::Value *codegen(std::shared_ptr<CodegenContext>) override;
    };

    std::shared_ptr<Function> convert(std::shared_ptr<ConvertContext>, BrillParser::FunctionDeclarationContext*);
}
