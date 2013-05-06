# CMake build for CompilerRT.
#
project(cxxstub)
# The CompilerRT build system requires CMake version 2.8.8 or higher in order
# to use its support for building convenience "libraries" as a collection of
# .o files. This is particularly useful in producing larger, more complex
# runtime libraries.
cmake_minimum_required(VERSION 2.8.8)


set(GENERIC_SOURCES
	stub.cpp
  )
add_library(cxxstub-static STATIC ${GENERIC_SOURCES})
set_target_properties(cxxstub-static PROPERTIES
                      OUTPUT_NAME "cxxstub"
                     )

install(TARGETS cxxstub-static
  ARCHIVE DESTINATION lib
  )
