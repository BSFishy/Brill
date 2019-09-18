
antlr4_generate(
        antlr
        ${CMAKE_CURRENT_SOURCE_DIR}/Brill.g4
        BOTH
        TRUE
        TRUE
        "Brill"
)

set(ANTLR_INCLUDES ${ANTLR4_INCLUDE_DIR_antlr} PARENT_SCOPE)
include_directories( ${PROJECT_BINARY_DIR} ${ANTLR4_INCLUDE_DIR} ${ANTLR4_INCLUDE_DIR_antlr} )

add_library(lang brill.cpp BrillParseTreeListener.cpp ${ANTLR4_SRC_FILES_antlr})

add_dependencies(lang antlr4_shared)
target_link_libraries(lang PRIVATE antlr4_shared)
