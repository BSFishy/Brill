
include_directories(.)

add_library(bir SHARED bir.cpp)

add_dependencies(bir antlr4_shared parser)
target_link_libraries(bir PRIVATE parser)
