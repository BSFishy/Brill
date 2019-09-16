
project(lang VERSION 0.1 DESCRIPTION "Brill language library")

antlr4_generate(
        brill_antlr
        ${CMAKE_CURRENT_SOURCE_DIR}/Brill.g4
        BOTH
        TRUE
        TRUE
        "Brill"
)

message("a - ${ANTLR4_INCLUDE_DIR_brill_antlr}")
include_directories( ${PROJECT_BINARY_DIR} ${ANTLR4_INCLUDE_DIR} ${ANTLR4_INCLUDE_DIR_brill_antlr} )

message("${ANTLR4_SRC_FILES_brill_antlr}")
add_library(lang brill.cpp brill.h ${ANTLR4_SRC_FILES_brill_antlr} BrillParseTreeListener.cpp BrillParseTreeListener.h)

add_dependencies(lang antlr4_shared)
target_link_libraries(lang PRIVATE antlr4_shared)
