set(LLVM_TOP_DIR /opt/llvm)
include_directories(${LLVM_TOP_DIR}/include)
add_definitions(
	-D__STDC_LIMIT_MACROS
	-D__STDC_CONSTANT_MACROS
)
macro(add_xclang_executable name)
  add_executable( ${name} ${ARGN} )
  set_target_properties(${name} PROPERTIES FOLDER "Xclang executables")
endmacro(add_clang_executable)

