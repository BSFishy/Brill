
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB_RECURSE ast_sources ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_library(ast SHARED ${ast_sources})

add_dependencies(ast antlr4_shared ${llvm_libs} util parser)
target_link_libraries(ast PRIVATE util parser antlr4_shared ${llvm_libs})
