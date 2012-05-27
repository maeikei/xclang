add_xclang_executable(xclang-engine
  driver.cpp
  cc1_main.cpp
  cc1as_main.cpp
  )
install(TARGETS xclang-engine DESTINATION ${PROJECT_BINARY_DIR}/InstallRoot/bin)