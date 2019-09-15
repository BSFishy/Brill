cmake_minimum_required(VERSION 3.5)

message("module path: ${CMAKE_SOURCE_DIR}")

project (Brill)
set (Brill_VERSION_MAJOR 0)
set (Brill_VERSION_MINOR 1)

set(CMAKE_PREFIX_PATH /usr/local/lib/cmake/antlr4 ${CMAKE_PREFIX_PATH})
set(ANTLR4_JAR_LOCATION /usr/local/lib/antlr-4.7.2-complete.jar)
find_package(antlr4-generator REQUIRED)
find_package(antlr4-runtime REQUIRED)

add_subdirectory(src/lang)

include_directories( ${PROJECT_BINARY_DIR} ${ANTLR4_INCLUDE_DIR} )

add_executable(brill src/main.cpp)
add_dependencies(brill antlr4_shared lang)
target_link_libraries(brill PUBLIC lang)
target_link_libraries(brill PRIVATE antlr4_shared)
