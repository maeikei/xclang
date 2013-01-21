link_directories(${CMAKE_BINARY_DIR}/3rdpart_build/lib)
set(XCLANG_SUFFIX "")
set(XCLANG xclang${XCLANG_SUFFIX})
add_executable(${XCLANG}
  main.cpp
  )
target_link_libraries( ${XCLANG} options driver lua driver options)
target_link_libraries( ${XCLANG} 
	boost_filesystem 
	boost_system 
	boost_regex 
	boost_program_options
)
install(TARGETS ${XCLANG} DESTINATION ${PROJECT_BINARY_DIR}/InstallRoot/bin)

set(XCLANG_SUFFIX "++")
set(XCLANG xclang${XCLANG_SUFFIX})
add_executable(${XCLANG}
  main.cpp
  )
target_link_libraries( ${XCLANG} options driver lua driver options)
target_link_libraries( ${XCLANG} 
	boost_filesystem 
	boost_system 
	boost_regex 
	boost_program_options
)
install(TARGETS ${XCLANG} DESTINATION ${PROJECT_BINARY_DIR}/InstallRoot/bin)

