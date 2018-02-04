cmake_minimum_required(VERSION 3.9)
set(CMAKE_CXX_STANDARD 11)

project(bb)

set(SOURCES
    ../src/bb/graph.cpp
    ../src/bb/graph.h)

add_library(${CMAKE_PROJECT_NAME} ${SOURCES})
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC src)

set(TEST_INCLUDES
    third-party/catch/catch.hpp)

set(TEST_SOURCES
    test/main.cpp
    test/graph-test.cpp)

enable_testing()
add_executable(${CMAKE_PROJECT_NAME}-test ${TEST_SOURCES} ${TEST_INCLUDES})
target_link_libraries(${CMAKE_PROJECT_NAME}-test PUBLIC ${CMAKE_PROJECT_NAME} pthread)
target_include_directories(${CMAKE_PROJECT_NAME}-test PUBLIC src test third-party/catch)
include(./third-party/catch/ParseAndAddCatchTests.cmake)
ParseAndAddCatchTests(${CMAKE_PROJECT_NAME}-test)
