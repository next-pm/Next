########################
#     Config  of       #
#       Project        #
########################
cmake_minimum_required (VERSION 3.0.0)

project (main VERSION 1.2.3)

#########################
#   Name of Executable  #
#                       #
#########################
set(APP next)

########################
#     Main Dirs of     #
#       Project        #
########################
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(BUILD_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build)
set(INCLUDE_TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/test/googletest/googletest/include)

########################
#    Include Dirs of   #
#       Project        #
########################
include_directories(
    .
    ${INCLUDE_DIR}
    ${INCLUDE_TEST_DIR}
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
    ${APP} 
    ${LIB_SOURCES} 
    ${LIB_HEADERS}
)
########################
#     Include Libs     #
########################

if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/libs.cmake)
    include(${CMAKE_CURRENT_SOURCE_DIR}/libs.cmake)
endif()

target_link_libraries(${APP} ${LIBS_PROYECT})

########################
#       Testing        #
########################
if( test AND test STREQUAL "on" )

  message("Testing enabled")

    ########################
    #     Test_SOURCE      #
    ########################
    file(GLOB TEST_SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/test/*.cpp)
    set(TESTING_SOURCE ${LIB_SOURCES} )
    list(REMOVE_ITEM TESTING_SOURCE ${SOURCE_DIR}/main.cpp)

    ########################
    #     Init_Testing     #
    ########################
    enable_testing()
    add_executable(runUnitTests_cmake_test ${TEST_SRC_FILES} ${TESTING_SOURCE} )

    ########################
    #  Library of Testing  #
    ########################
    add_subdirectory(test/googletest)

    list(APPEND LIBS_GTEST gtest gtest_main pthread)
    
    target_link_libraries(runUnitTests_cmake_test PRIVATE
        ${LIBS_PROYECT}
        ${LIBS_GTEST}
    )

    ########################
    #   Build of Testing   #
    ######################## 
    add_test(UnitTests runUnitTests_cmake_test)
else()

    ########################
    #  Dir of the binary   #
    ########################
    set(EXECUTABLE_OUTPUT_PATH ${BUILD_DIR} CACHE PATH "Build directory" FORCE)
    set(CMAKE_BINARY_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/build)
endif()