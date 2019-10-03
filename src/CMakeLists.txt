
# Util
include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/util/)

add_library(util SHARED ${CMAKE_CURRENT_SOURCE_DIR}/util/util.h)
set_target_properties(util PROPERTIES LINKER_LANGUAGE CXX)

# Lang
add_subdirectory(lang)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/lang/ ${CMAKE_CURRENT_SOURCE_DIR}/lang/bir/)

# Main

add_executable(brill main.cpp)

add_dependencies(brill antlr4_shared ${llvm_libs} util parser lang bir)
target_link_libraries(brill PRIVATE util parser bir lang antlr4_shared ${llvm_libs})
