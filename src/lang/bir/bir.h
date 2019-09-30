
#pragma once

#include <memory>
#include <brill.h>

// Abstract tree parts
#include "tree/abstract/code_generator.h"
#include "tree/abstract/named.h"
#include "tree/abstract/code_block.h"
#include "tree/type.h"
#include "tree/symbol/symbol.h"
#include "tree/symbol/symbol_table.h"

#include "tree/container/container.h"
#include "tree/container/variable_container.h"
#include "tree/container/function_container.h"
#include "tree/container/protocol_container.h"
#include "tree/container/class_container.h"
#include "tree/container/enum_container.h"
#include "tree/container/struct_container.h"
#include "tree/container/extension_container.h"

// Abstract concepts
#include "tree/module.h"
#include "tree/function/function.h"
#include "tree/constructs/construct.h"
#include "tree/constructs/class/class.h"
#include "tree/constructs/enum/enum.h"
#include "tree/constructs/extension/extension.h"
#include "tree/constructs/protocol/protocol.h"
#include "tree/constructs/struct/struct.h"
#include "tree/statements/statement.h"
#include "tree/variable/variable.h"
#include "tree/variable/declaration/variable_declaration.h"
#include "tree/variable/declaration/constant_variable_declaration.h"
#include "tree/declarations/declaration.h"

// Implementations
#include "tree/declarations/impl/import_declaration.h"

namespace Brill::IR {
    std::unique_ptr<Declaration> convert(Brill::BrillParser::TopLevelContext *);
}
