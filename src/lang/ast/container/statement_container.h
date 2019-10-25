
#pragma once

#include <vector>

#include "container.h"
#include "lang/ast/abstract/codegen_context.h"
#include "lang/ast/symbol_table.h"

namespace Brill::AST {
    class Statement;

    class StatementContainer : public virtual Container {
    public:
        std::vector<Statement*> statements;

        void addStatement(Statement*);
        bool removeStatement(Statement*);

        void codegenStatements(std::shared_ptr<CodegenContext>);
    };
}
