
# Util
include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/util/)

add_library(util SHARED ${CMAKE_CURRENT_SOURCE_DIR}/util/util.h)
set_target_properties(util PROPERTIES LINKER_LANGUAGE CXX)

# Lang
add_subdirectory(lang)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/lang/ ${CMAKE_CURRENT_SOURCE_DIR}/lang/bir/ ${CMAKE_CURRENT_SOURCE_DIR}/lang/ast)

# Main

add_executable(brill main.cpp)

add_dependencies(brill antlr4_shared ${llvm_libs} util parser lang bir ast)
target_link_libraries(brill PRIVATE util parser bir ast lang antlr4_shared ${llvm_libs})
