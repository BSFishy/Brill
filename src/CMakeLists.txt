
add_subdirectory(lang)

include_directories(lang/)

add_executable(brill main.cpp)

add_dependencies(brill antlr4_shared ${llvm_libs} parser lang bir)
target_link_libraries(brill PRIVATE parser lang bir)