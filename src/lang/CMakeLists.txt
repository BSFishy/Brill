
antlr4_generate(
        antlr
        ${CMAKE_CURRENT_SOURCE_DIR}/Brill.g4
        BOTH
        TRUE
        TRUE
        "Brill"
)

set(ANTLR_INCLUDES ${ANTLR4_INCLUDE_DIR_antlr} PARENT_SCOPE)
add_subdirectory(bir)

include_directories(${ANTLR4_INCLUDE_DIR_antlr} .)

add_library(lang SHARED brill.cpp compiler.cpp codegen/codegen.cpp ${ANTLR4_SRC_FILES_antlr})

add_dependencies(lang antlr4_shared ${llvm_libs} bir)
target_link_libraries(lang PRIVATE bir)
