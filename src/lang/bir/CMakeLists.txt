
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB_RECURSE bir_sources *.cpp)

add_library(bir SHARED ${bir_sources})

add_dependencies(bir antlr4_shared ${llvm_libs} util parser)
target_link_libraries(bir PRIVATE util parser antlr4_shared ${llvm_libs})
