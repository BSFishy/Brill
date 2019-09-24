cmake_minimum_required(VERSION 3.5)

project(brill VERSION 0.1 DESCRIPTION "Brill language")

set(CMAKE_PREFIX_PATH /usr/local/lib/cmake/antlr4 ${CMAKE_PREFIX_PATH})

if (EXISTS /usr/local/lib/antlr-4.7.2-complete.jar)
    set(ANTLR4_JAR_LOCATION /usr/local/lib/antlr-4.7.2-complete.jar)
elseif (EXISTS /usr/share/java/antlr4-4.7.2.jar)
    set(ANTLR4_JAR_LOCATION /usr/share/java/antlr4-4.7.2.jar)
else ()
    message(FATAL_ERROR "Could not find a valid antlr jar file.")
endif ()

find_package(LLVM REQUIRED CONFIG)

find_package(antlr4-generator REQUIRED)
find_package(antlr4-runtime REQUIRED)

if ( EXISTS /usr/include/llvm-10 AND $ENV{CLION_IDE} )
    include_directories(/usr/include/llvm-10)
endif ()

include_directories(${PROJECT_BINARY_DIR} ${LLVM_INCLUDE_DIRS} ${ANTLR4_INCLUDE_DIR})
llvm_map_components_to_libnames(llvm_libs support core)
add_definitions(${LLVM_DEFINITIONS})

link_libraries(antlr4_shared ${llvm_libs})

add_subdirectory(src)
