
#pragma once

// Abstract tree parts
#include "tree/abstract/codegen/codegen_context.h"
#include "tree/abstract/codegen/code_generator.h"
#include "tree/abstract/codegen/value_generator.h"
#include "tree/abstract/named.h"
#include "tree/abstract/code_block.h"
#include "tree/type.h"
#include "tree/symbol/symbol.h"
#include "tree/symbol/symbol_table.h"
#include "tree/expression/expression.h"
#include "tree/expression/prefix_expression.h"

#include "tree/expression/postfix/postfix_expression.h"
#include "tree/expression/postfix/explicit_member_expression.h"
#include "tree/expression/postfix/forced_value_expression.h"
#include "tree/expression/postfix/function_call_expression.h"
#include "tree/expression/postfix/initializer_expression.h"
#include "tree/expression/postfix/optional_chaining_expression.h"
#include "tree/expression/postfix/postfix_operator_expression.h"
#include "tree/expression/postfix/postfix_primary_expression.h"
#include "tree/expression/postfix/postfix_self_expression.h"
#include "tree/expression/postfix/subscript_expression.h"

#include "tree/expression/primary/primary_expression.h"
#include "tree/expression/primary/identifier_expression.h"

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
#include "tree/statement/statement.h"
#include "tree/variable/variable.h"
#include "tree/declarations/declaration.h"

// Implementations
#include "tree/declarations/impl/import_declaration.h"

#include "tree/variable/declaration/variable_declaration.h"
#include "tree/variable/declaration/constant_variable_declaration.h"

#include "tree/statement/call_statement.h"
#include "tree/statement/expression_statement.h"


#include "tree/modules.h"
