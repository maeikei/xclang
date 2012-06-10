include_directories(${PROJECT_SOURCE_DIR}/libdriver)
add_xclang_executable(xclang-engine
  driver.cpp
  cc1_main.cpp
  cc1as_main.cpp
  lua_config_reader.cpp
  )
target_link_libraries( xclang-engine lua)
install(TARGETS xclang-engine DESTINATION ${PROJECT_BINARY_DIR}/InstallRoot/bin)