cmake_minimum_required(VERSION 3.5)

project(brill VERSION 0.1 DESCRIPTION "Brill language")
set (CMAKE_CXX_STANDARD 17)

# Antlr stuff

set(CMAKE_PREFIX_PATH /usr/local/lib/cmake/antlr4 ${CMAKE_PREFIX_PATH})

if (EXISTS /usr/local/lib/antlr-4.7.2-complete.jar)
    set(ANTLR4_JAR_LOCATION /usr/local/lib/antlr-4.7.2-complete.jar)
elseif (EXISTS /usr/share/java/antlr4-4.7.2.jar)
    set(ANTLR4_JAR_LOCATION /usr/share/java/antlr4-4.7.2.jar)
else ()
    message(FATAL_ERROR "Could not find a valid antlr jar file.")
endif ()

find_package(antlr4-generator REQUIRED)
find_package(antlr4-runtime REQUIRED)

antlr4_generate(
        parser
        ${PROJECT_SOURCE_DIR}/src/lang/Brill.g4
        BOTH
        TRUE
        TRUE
        "Brill"
)

include_directories(${ANTLR4_INCLUDE_DIR} ${ANTLR4_INCLUDE_DIR_parser})
add_library(parser SHARED ${ANTLR4_SRC_FILES_parser})
add_dependencies(parser antlr4_shared)

# LLVM stuff

find_package(LLVM REQUIRED CONFIG)

if ( $ENV{CLION_IDE} )
    if ( EXISTS /usr/include/llvm-10 )
        include_directories(/usr/include/llvm-10)
    endif ()
endif ()

include_directories(${PROJECT_BINARY_DIR} ${LLVM_INCLUDE_DIRS})
llvm_map_components_to_libnames(llvm_libs support core native)
add_definitions(${LLVM_DEFINITIONS})

link_libraries(${llvm_libs})

add_subdirectory(src)
