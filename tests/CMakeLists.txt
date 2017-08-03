cmake_minimum_required(VERSION 2.8.11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

file(GLOB_RECURSE SRC "*.h"
                      "*.cpp")

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

find_package(Qt5Quick)

add_executable(tests ${SRC})
include_directories ("${CMAKE_SOURCE_DIR}/common")
include_directories ("${CMAKE_SOURCE_DIR}/3rdParty/googletest/googlemock/include")
include_directories ("${CMAKE_SOURCE_DIR}/3rdParty/googletest/googletest/include")

target_link_libraries(tests Qt5::Quick)
target_link_libraries(tests ${CMAKE_BINARY_DIR}/common/libcommon.a )
target_link_libraries(tests ${CMAKE_BINARY_DIR}/3rdParty/googletest/googlemock/libgmock.a -lpthread -lm)
target_link_libraries(tests ${CMAKE_BINARY_DIR}/3rdParty/googletest/googlemock/gtest/libgtest.a -lpthread -lm)
