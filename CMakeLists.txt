project(xclang)
cmake_minimum_required(VERSION 2.8)

if(MACOSX)
set( CMAKE_C_COMPILER /opt/gcc-4.6.1/bin/gcc)
set( CMAKE_CXX_COMPILER /opt/gcc-4.6.1/bin/g++)
set( CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=c++0x)
endif(MACOSX)


include(clang.define.cmake)
include_directories(${PROJECT_SOURCE_DIR}/3rdpart_build/lua/include)
add_subdirectory(3rdpart_build)
add_subdirectory(libdriver)
add_subdirectory(driver)
add_subdirectory(Root)