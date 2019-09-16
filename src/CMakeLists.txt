
project(brill VERSION 0.1 DESCRIPTION "Brill language")

include_directories( ${PROJECT_BINARY_DIR} ${ANTLR4_INCLUDE_DIR} lang/ )

add_executable(brill main.cpp)

add_dependencies(brill antlr4_shared lang)
target_link_libraries(brill PRIVATE antlr4_shared lang)