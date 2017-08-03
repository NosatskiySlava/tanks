cmake_minimum_required(VERSION 2.8.11)

project(common)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

file(GLOB_RECURSE SRC "*.h"
                      "*.cpp")

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

# Find the QtWidgets library
find_package(Qt5Quick)
find_package(Qt5Qml)

add_library(common ${SRC})

target_link_libraries(common Qt5::Quick)
target_link_libraries(common Qt5::Qml)
