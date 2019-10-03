
#pragma once

#include <memory>

#include "BrillParser.h"

#include "tree/abstract/codegen/codegen_context.h"
#include "tree/statement/statement.h"

namespace Brill::IR::Convert {
    std::shared_ptr<Statement> convert(BrillParser::StatementContext *);
}
