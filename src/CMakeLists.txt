
# Util
include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/util/)

# Lang
add_subdirectory(lang)

# Main

add_executable(brill main.cpp)

add_dependencies(brill antlr4_shared ${llvm_libs} parser lang ast)
target_link_libraries(brill PRIVATE parser ast lang antlr4_shared ${llvm_libs})
