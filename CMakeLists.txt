cmake_minimum_required(VERSION 2.8.11)

project(common)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -g -O0 --coverage -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE 1)

add_subdirectory(3rdParty/googletest)
add_subdirectory(common)
add_subdirectory(app)
add_subdirectory(tests)
