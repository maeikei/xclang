
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} /opt/llvm/share/llvm/cmake)
#include(${LLVM_TOP}/share/llvm/cmake/LLVMProcessSources.cmake)
include(AddLLVM)
#find_package(LLVM)

macro(add_clang_executable name)
  add_llvm_executable( ${name} ${ARGN} )
  set_target_properties(${name} PROPERTIES FOLDER "Clang executables")
endmacro(add_clang_executable)

