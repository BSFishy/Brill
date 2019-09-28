
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_library(bir SHARED bir.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/abstract/name/impl/module_name.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/abstract/name/impl/variable_name.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/abstract/name/impl/function_name.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/abstract/name/impl/protocol_name.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/abstract/name/impl/class_name.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/abstract/name/impl/enum_name.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/abstract/name/impl/struct_name.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/abstract/name/impl/extension_name.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/tree/declarations/impl/import_declaration.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/tree/variable/variable.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/tree/variable/declaration/variable_declaration.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/tree/variable/declaration/constant_variable_declaration.cpp)

add_dependencies(bir antlr4_shared util parser)
target_link_libraries(bir PRIVATE util parser)
