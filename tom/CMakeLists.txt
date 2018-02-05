cmake_minimum_required(VERSION 3.9)
set(CMAKE_CXX_STANDARD 11)

project(bb)

set(SOURCES
    src/bb/random-walk.h
    src/bb/constants.cpp
    src/bb/constants.h
    src/bb/graph.cpp
    src/bb/graph.h
    src/bb/life.h
    src/bb/lines.h)

add_library(${CMAKE_PROJECT_NAME} ${SOURCES})
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC src)

set(TEST_INCLUDES
    test/bb/functions.h
    src/bb/random-walk.h
    test/simple-graph.h)

set(TEST_SOURCES
    test/bb/functions.cpp
    test/functions-test.cpp
    test/graph-test.cpp
    test/main.cpp
    test/random-walk-test.cpp)

enable_testing()
set(TEST ${CMAKE_PROJECT_NAME}-test)
add_executable(${TEST} ${TEST_SOURCES} ${TEST_INCLUDES})
target_link_libraries(${TEST} PUBLIC ${CMAKE_PROJECT_NAME})
target_include_directories(${TEST} PUBLIC src test third-party)

include(./third-party/catch/ParseAndAddCatchTests.cmake)
ParseAndAddCatchTests(${CMAKE_PROJECT_NAME}-test)
