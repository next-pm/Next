cmake_minimum_required(VERSION 2.8.11)
project(HELLO)

set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(BUILD_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build)

include_directories(
    .
    ${INCLUDE_DIR}
)

#message("SOURCE_DIR = ${SOURCE_DIR}")
#message("INCLUDE_DIR = ${INCLUDE_DIR}")
#message("BUILD_DIR = ${BUILD_DIR}")

set(EXECUTABLE_OUTPUT_PATH ${BUILD_DIR} CACHE PATH "Build directory" FORCE)
set(CMAKE_BINARY_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/build)

file( GLOB_RECURSE LIB_SOURCES ${SOURCE_DIR}/*.cpp )
file( GLOB_RECURSE LIB_HEADERS ${INCLUDE_DIR}/*.hpp )

add_executable( app ${LIB_SOURCES} ${LIB_HEADERS} )