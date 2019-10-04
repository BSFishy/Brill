
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_library(bir SHARED
        ${CMAKE_CURRENT_SOURCE_DIR}/tree/module.cpp

        ${CMAKE_CURRENT_SOURCE_DIR}/tree/declarations/impl/import_declaration.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/tree/variable/variable.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/tree/variable/declaration/variable_declaration.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/tree/variable/declaration/constant_variable_declaration.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/tree/function/function.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/tree/function/argument.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/tree/container/class_container.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/tree/container/function_container.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/tree/container/statement_container.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/tree/expression/constant/string_constant.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/tree/statement/call_statement.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/tree/statement/expression_statement.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/tree/expression/expression.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/tree/expression/prefix_expression.cpp

        ${CMAKE_CURRENT_SOURCE_DIR}/tree/expression/primary/identifier_expression.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/tree/expression/primary/literal_literal_expression.cpp

        ${CMAKE_CURRENT_SOURCE_DIR}/tree/expression/postfix/explicit_member_expression.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/tree/expression/postfix/forced_value_expression.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/tree/expression/postfix/function_call_expression.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/tree/expression/postfix/initializer_expression.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/tree/expression/postfix/optional_chaining_expression.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/tree/expression/postfix/postfix_operator_expression.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/tree/expression/postfix/postfix_primary_expression.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/tree/expression/postfix/postfix_self_expression.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/tree/expression/postfix/subscript_expression.cpp

        ${CMAKE_CURRENT_SOURCE_DIR}/tree/expression/literal/string_literal.cpp

        ${CMAKE_CURRENT_SOURCE_DIR}/convert/top_level.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/convert/function/function.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/convert/function/argument.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/convert/statement/statement.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/convert/expression/expression.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/convert/expression/prefix_expression.cpp

        ${CMAKE_CURRENT_SOURCE_DIR}/convert/expression/primary/primary_expression.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/convert/expression/primary/identifier_expression.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/convert/expression/primary/literal_expression.cpp

        ${CMAKE_CURRENT_SOURCE_DIR}/convert/expression/postfix/postfix_expression.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/convert/expression/postfix/function_call_expression.cpp

        ${CMAKE_CURRENT_SOURCE_DIR}/convert/expression/literal/literal.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/convert/expression/literal/string_literal.cpp

        ${CMAKE_CURRENT_SOURCE_DIR}/tree/modules.cpp)

add_dependencies(bir antlr4_shared ${llvm_libs} util parser)
target_link_libraries(bir PRIVATE util parser antlr4_shared ${llvm_libs})
