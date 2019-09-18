
#message("${ANTLR4_INCLUDE_DIR_antlr}")
include_directories( ${PROJECT_BINARY_DIR} ${ANTLR4_INCLUDE_DIR} ${ANTLR4_INCLUDE_DIR_antlr} )

#message("${ANTLR4_SRC_FILES_antlr}")
add_library(lang brill.cpp BrillParseTreeListener.cpp ${ANTLR4_SRC_FILES_antlr})

add_dependencies(lang antlr4_shared)
target_link_libraries(lang PRIVATE antlr4_shared)
