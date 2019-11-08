
add_library(lang SHARED brill.cpp)

add_dependencies(lang antlr4_shared ${llvm_libs} ast parser)
target_link_libraries(lang PRIVATE ast parser antlr4_shared ${llvm_libs})

add_subdirectory(ast)
