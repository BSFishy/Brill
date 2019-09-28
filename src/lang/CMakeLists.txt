
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_library(lang SHARED brill.cpp compiler.cpp codegen/codegen.cpp)

add_dependencies(lang antlr4_shared ${llvm_libs} util bir parser)
target_link_libraries(lang PRIVATE util bir parser)

add_subdirectory(bir)
