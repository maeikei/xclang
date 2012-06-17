if(WIN32)
set(LLVM_TOP_DIR E:/develop/llvm-dev/install)
else(WIN32)
set(LLVM_TOP_DIR /opt/llvm)
endif(WIN32)
include_directories(${LLVM_TOP_DIR}/include)

configure_file(
  ${CMAKE_SOURCE_DIR}/Config/config.h.cmake
  ${CMAKE_BINARY_DIR}/include/clang/Config/config.h
)
include_directories(${CMAKE_BINARY_DIR}/include)


add_definitions(
	-D__STDC_LIMIT_MACROS
	-D__STDC_CONSTANT_MACROS
)
link_directories(${LLVM_TOP_DIR}/lib)
macro(add_xclang_executable name)
  add_executable( ${name} ${ARGN} )
  target_link_libraries( ${name}
## llvm clang --libs
##
xClangDriver
##
clangFrontendTool clangAST clangAnalysis clangBasic clangCodeGen 
clangEdit clangFrontend clangLex clangParse clangEdit 
clangARCMigrate clangRewrite clangSema clangSerialization clangStaticAnalyzerFrontend 
clangStaticAnalyzerCheckers clangStaticAnalyzerCore LLVMARMCodeGen LLVMARMAsmParser 
LLVMARMDisassembler LLVMCellSPUCodeGen LLVMCppBackendCodeGen LLVMHexagonCodeGen 
LLVMMipsCodeGen LLVMMipsAsmParser LLVMMipsDisassembler LLVMMBlazeCodeGen 
LLVMMBlazeAsmParser LLVMMBlazeDisassembler LLVMMSP430CodeGen 
#LLVMNVPTXCodeGen 
LLVMPowerPCCodeGen
LLVMPTXCodeGen
LLVMSparcCodeGen LLVMX86CodeGen LLVMX86AsmParser 
LLVMX86Disassembler LLVMXCoreCodeGen LLVMAsmParser LLVMBitWriter LLVMInstrumentation 
LLVMipo LLVMLinker LLVMARMDesc LLVMCellSPUDesc LLVMCppBackendInfo LLVMHexagonAsmPrinter 
LLVMHexagonDesc LLVMMipsDesc LLVMMBlazeDesc LLVMMSP430Desc 
#LLVMNVPTXDesc
LLVMPowerPCDesc 
LLVMPTXDesc
LLVMSparcDesc LLVMX86Desc LLVMAsmPrinter LLVMSelectionDAG LLVMXCoreDesc 
LLVMVectorize LLVMArchive LLVMARMAsmPrinter LLVMARMInfo LLVMCellSPUInfo 
LLVMHexagonInfo LLVMMipsAsmPrinter LLVMMipsInfo LLVMMBlazeAsmPrinter 
LLVMMBlazeInfo LLVMMSP430AsmPrinter LLVMMSP430Info 
#LLVMNVPTXAsmPrinter 
#LLVMNVPTXInfo
LLVMPowerPCAsmPrinter LLVMPowerPCInfo LLVMPTXAsmPrinter 
LLVMPTXInfo LLVMSparcInfo LLVMX86AsmPrinter LLVMX86Info LLVMMCParser 
LLVMCodeGen LLVMXCoreInfo LLVMBitReader LLVMX86Utils LLVMScalarOpts 
LLVMInstCombine LLVMTransformUtils LLVMipa LLVMAnalysis LLVMTarget 
LLVMCore LLVMMC LLVMObject LLVMSupport clangRewrite clangFrontend 
clangSerialization clangParse clangSema clangAnalysis clangEdit 
clangAST clangLex clangBasic LLVMMC LLVMObject LLVMSupport
pthread
   )
   
  if(WIN32)
    target_link_libraries( ${name}
      -limagehlp -lpsapi -lkernel32 -luser32 -lgdi32 -lwinspool -lshell32 -lole32 -loleaut32 -luuid -lcomdlg32 -ladvapi32 
    )
  endif(WIN32)
  set_target_properties(${name} PROPERTIES FOLDER "Xclang executables")
endmacro(add_xclang_executable)


macro(add_xclang_library name)
  add_library( ${name} ${ARGN} )
endmacro(add_xclang_library)
