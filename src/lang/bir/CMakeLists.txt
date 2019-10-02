
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_library(bir SHARED
        ${CMAKE_CURRENT_SOURCE_DIR}/tree/declarations/impl/import_declaration.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/tree/variable/variable.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/tree/variable/declaration/variable_declaration.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/tree/variable/declaration/constant_variable_declaration.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/tree/function/function.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/tree/container/class_container.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/tree/container/statement_container.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/tree/expression/constant/string_constant.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/tree/statement/call_statement.cpp

        ${CMAKE_CURRENT_SOURCE_DIR}/convert/top_level.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/convert/function/function.cpp)

add_dependencies(bir antlr4_shared util parser)
target_link_libraries(bir PRIVATE antlr4_shared util parser)
