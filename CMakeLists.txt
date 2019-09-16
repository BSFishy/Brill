cmake_minimum_required(VERSION 3.5)

set(CMAKE_PREFIX_PATH /usr/local/lib/cmake/antlr4 ${CMAKE_PREFIX_PATH})
set(ANTLR4_JAR_LOCATION /usr/local/lib/antlr-4.7.2-complete.jar)
find_package(antlr4-generator REQUIRED)
find_package(antlr4-runtime REQUIRED)

add_subdirectory(src/lang)
add_subdirectory(src)
