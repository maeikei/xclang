set(LLVM_TOP_DIR /opt/llvm)
include_directories(${LLVM_TOP_DIR}/include)
add_definitions(
	-D__STDC_LIMIT_MACROS
	-D__STDC_CONSTANT_MACROS
)
link_directories(${LLVM_TOP_DIR}/lib)
macro(add_xclang_executable name)
  add_executable( ${name} ${ARGN} )
  target_link_libraries( ${name}
  LLVMAsmParser
  LLVMBitReader
  LLVMBitWriter
  LLVMCodeGen
  LLVMInstrumentation
  LLVMipo
  LLVMLinker
  LLVMSelectionDAG

  clangFrontendTool
  clangAST
  clangAnalysis
  clangBasic
  clangCodeGen
  clangDriver
  clangEdit
  clangFrontend
  clangLex
  clangParse
  clangEdit
  clangARCMigrate
  clangRewrite
  clangSema
  clangSerialization
  clangStaticAnalyzerFrontend
  clangStaticAnalyzerCheckers
  clangStaticAnalyzerCore
   
   )
  set_target_properties(${name} PROPERTIES FOLDER "Xclang executables")
endmacro(add_xclang_executable)

