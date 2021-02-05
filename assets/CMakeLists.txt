########################
#     Config  of       #
#       Project        #
########################
cmake_minimum_required (VERSION 3.0.0)

project (main VERSION 1.2.3)

########################
#     Main Dirs of     #
#       Project        #
########################
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(BUILD_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build)

########################
#    Include Dirs of   #
#       Project        #
########################
include_directories(
    .
    ${INCLUDE_DIR}
)

########################
#    Find Source of    #
#       Project        #
########################
file( GLOB_RECURSE LIB_SOURCES ${SOURCE_DIR}/*.cpp )
file( GLOB_RECURSE LIB_HEADERS ${INCLUDE_DIR}/*.hpp )

########################
#     Add Source of    #
#       Project        #
########################
add_executable(
    app 
    ${LIB_SOURCES} 
    ${LIB_HEADERS}
)

########################
#     Include Libs     #
########################
if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/libs.cmake)
    include(${CMAKE_CURRENT_SOURCE_DIR}/libs.cmake)
endif()

########################
#  Dir of the binary   #
########################
set(EXECUTABLE_OUTPUT_PATH ${BUILD_DIR} CACHE PATH "Build directory" FORCE)
set(CMAKE_BINARY_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/build)