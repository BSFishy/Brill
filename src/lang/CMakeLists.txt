
antlr4_generate(
        antlr
        ${CMAKE_CURRENT_SOURCE_DIR}/Brill.g4
        BOTH
        FALSE
        TRUE
        "Brill"
)

include_directories( ${PROJECT_BINARY_DIR} ${ANTLR4_INCLUDE_DIR} ${ANTLR4_INCLUDE_DIR_antlr} )

add_library(lang brill.cpp ${ANTLR4_SRC_FILES_antlr})
add_dependencies(lang antlr4_shared)
target_link_libraries(lang PRIVATE antlr4_shared)
