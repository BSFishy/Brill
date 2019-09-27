
include_directories(.)

add_library(lang SHARED brill.cpp compiler.cpp codegen/codegen.cpp)

add_dependencies(lang antlr4_shared ${llvm_libs} bir parser)
target_link_libraries(lang PRIVATE bir parser)

add_subdirectory(bir)
