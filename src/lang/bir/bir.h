
#pragma once

#include <memory>
#include <brill.h>

// Abstract parts
#include "abstract/name/name.h"
#include "abstract/name/mangleable.h"
#include "abstract/name/parented_name.h"

#include "abstract/name/impl/module_name.h"
#include "abstract/name/impl/variable_name.h"
#include "abstract/name/impl/function_name.h"
#include "abstract/name/impl/protocol_name.h"
#include "abstract/name/impl/class_name.h"
#include "abstract/name/impl/enum_name.h"
#include "abstract/name/impl/struct_name.h"
#include "abstract/name/impl/extension_name.h"

// Abstract tree parts
#include "tree/abstract/code_generator.h"
#include "tree/abstract/named.h"
#include "tree/abstract/code_block.h"

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
