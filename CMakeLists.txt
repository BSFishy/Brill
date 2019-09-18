cmake_minimum_required(VERSION 3.5)

project(brill VERSION 0.1 DESCRIPTION "Brill language")

set(CMAKE_PREFIX_PATH /usr/local/lib/cmake/antlr4 ${CMAKE_PREFIX_PATH})

if(EXISTS /usr/local/lib/antlr-4.7.2-complete.jar)
    set(ANTLR4_JAR_LOCATION /usr/local/lib/antlr-4.7.2-complete.jar)
elseif(EXISTS /usr/share/java/antlr4-4.7.2.jar)
    set(ANTLR4_JAR_LOCATION /usr/share/java/antlr4-4.7.2.jar)
else()
    message(FATAL_ERROR "Could not find a valid antlr jar file.")
endif()

find_package(antlr4-generator REQUIRED)
find_package(antlr4-runtime REQUIRED)

add_subdirectory(src)
