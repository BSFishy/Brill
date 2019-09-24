
add_subdirectory(lang)

include_directories(${ANTLR_INCLUDES} lang/)

add_executable(brill main.cpp)

add_dependencies(brill antlr4_shared lang ${llvm_libs})
target_link_libraries(brill PRIVATE lang)