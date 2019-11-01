
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB_RECURSE ast_sources *.cpp)

add_library(ast SHARED ${ast_sources})

add_dependencies(ast antlr4_shared ${llvm_libs} parser)
target_link_libraries(ast PRIVATE parser antlr4_shared ${llvm_libs})
