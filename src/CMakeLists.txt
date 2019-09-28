
# Util
include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/util/)

add_library(util SHARED ${CMAKE_CURRENT_SOURCE_DIR}/util/not_implemented_exception.h)

# Lang
add_subdirectory(lang)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/lang/)

# Main

add_executable(brill main.cpp)

add_dependencies(brill antlr4_shared ${llvm_libs} util parser lang bir)
target_link_libraries(brill PRIVATE util parser lang bir)