project(xclang)
cmake_minimum_required(VERSION 2.8)
include_directories(${PROJECT_SOURCE_DIR}/3rdpart_build/lua/src)
include_directories(${PROJECT_SOURCE_DIR}/driver)
include_directories(${CMAKE_BINARY_DIR}/3rdpart_build/include)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(3rdpart_build)
add_subdirectory(options)
add_subdirectory(driver)
add_subdirectory(executable)
add_subdirectory(config)
