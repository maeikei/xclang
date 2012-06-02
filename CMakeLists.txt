project(xclang)
cmake_minimum_required(VERSION 2.8)
include(clang.define.cmake)

if(WIN32)
	include_directories(${PROJECT_BINARY_DIR}/3rdpart/include/boost-1_46_1)
else(WIN32)
	include_directories(${PROJECT_BINARY_DIR}/3rdpart/include)
endif(WIN32)
include_directories(${PROJECT_SOURCE_DIR}/3rdpart_build/lua/include)
include_directories(${PROJECT_SOURCE_DIR}/3rdpart_build/luabind)


add_subdirectory(3rdpart_build)
add_subdirectory(libdriver)
add_subdirectory(driver)
add_subdirectory(Root)