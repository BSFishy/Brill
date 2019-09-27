
include_directories(${ANTLR4_INCLUDE_DIR_antlr} .)

add_library(bir SHARED bir.cpp)

add_dependencies(bir antlr4_shared)
