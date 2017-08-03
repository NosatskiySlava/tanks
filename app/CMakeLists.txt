cmake_minimum_required(VERSION 2.8.11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

file(GLOB_RECURSE SRC "*.h"
                      "*.cpp")

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

find_package(Qt5Quick)
find_package(Qt5Qml)

add_executable(app ${SRC})
include_directories ("${CMAKE_SOURCE_DIR}/common")

target_link_libraries(app Qt5::Quick)
target_link_libraries(app Qt5::Qml)
target_link_libraries(app ${CMAKE_BINARY_DIR}/common/libcommon.a)
