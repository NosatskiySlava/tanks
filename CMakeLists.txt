cmake_minimum_required(VERSION 2.8.11)

project(common)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

add_subdirectory(3rdParty/googletest)
add_subdirectory(common)
add_subdirectory(app)
add_subdirectory(tests)
