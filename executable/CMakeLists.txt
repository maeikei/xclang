link_directories(${CMAKE_BINARY_DIR}/3rdpart_build/lib)
set(XCLANG_PREFIX x86_64-pc-linux-gnueabi-)
set(XCLANG ${XCLANG_PREFIX}xclang)
add_executable(${XCLANG}
  main.cpp
  )
target_link_libraries( ${XCLANG} lua driver options)
target_link_libraries( ${XCLANG} 
	boost_filesystem 
	boost_system 
	boost_regex 
	boost_program_options
)
install(TARGETS ${XCLANG} DESTINATION ${PROJECT_BINARY_DIR}/InstallRoot/bin)