set(XCLANG_PREFIX x86_64-pc-linux-gnueabi-)
set(XCLANG ${XCLANG_PREFIX}xclang)
add_executable(${XCLANG}
  main.cpp
  )
target_link_libraries( ${XCLANG} lua driver)
install(TARGETS ${XCLANG} DESTINATION ${PROJECT_BINARY_DIR}/InstallRoot/bin)