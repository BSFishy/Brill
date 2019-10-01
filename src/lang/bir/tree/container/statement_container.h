
#pragma once

#include <list>
#include <memory>

#include "container.h"

namespace Brill::IR {
    class Statement;

    class StatementContainer {
    public:
        std::list<std::shared_ptr<Statement>> statements;

        void addStatement(std::shared_ptr<Statement>);
        size_t statementCount();
    };
}
