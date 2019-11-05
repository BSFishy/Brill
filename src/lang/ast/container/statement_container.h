
#pragma once

#include <vector>

#include "container.h"

namespace Brill::AST {
    class Statement;

    class StatementContainer : public virtual Container {
        std::vector<std::shared_ptr<Statement>> statements;
    public:
        void addStatement(const std::shared_ptr<Statement>&);
        bool removeStatement(const std::shared_ptr<Statement>&);

        std::vector<std::shared_ptr<Statement>> getStatements() const;
        void codegenStatements(const std::shared_ptr<CodegenContext>&) const;
    };
}
