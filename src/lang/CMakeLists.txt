
# include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/bir/ ${CMAKE_CURRENT_SOURCE_DIR}/ast)

add_library(lang SHARED brill.cpp compiler.cpp codegen/codegen.cpp)

# add_dependencies(lang antlr4_shared ${llvm_libs} util bir ast parser)
# target_link_libraries(lang PRIVATE util bir ast parser antlr4_shared ${llvm_libs})
add_dependencies(lang antlr4_shared ${llvm_libs} util ast parser)
target_link_libraries(lang PRIVATE util ast parser antlr4_shared ${llvm_libs})

add_subdirectory(ast)
# add_subdirectory(bir)
