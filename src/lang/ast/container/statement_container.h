
#pragma once

#include <vector>

#include "container.h"
#include "lang/ast/abstract/codegen_context.h"

namespace Brill::AST {
    class Statement;

    class StatementContainer : public virtual Container {
    public:
        std::vector<std::shared_ptr<Statement>> statements;

        void addStatement(const std::shared_ptr<Statement>&);
        bool removeStatement(const std::shared_ptr<Statement>&);

        void codegenStatements(const std::shared_ptr<CodegenContext>&);
    };
}
