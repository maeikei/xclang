# install lua script.
FILE(GLOB LUA_SCRIPT share/*.lua)
install(FILES ${LUA_SCRIPT} DESTINATION ${PROJECT_BINARY_DIR}/InstallRoot/share)


# install prebuild file.
#FILE(GLOB TAR_BALL platform/*.7z)
#install(FILES ${TAR_BALL} DESTINATION ${PROJECT_BINARY_DIR}/InstallRoot/platform)


# install header files.
FILE(GLOB HEADERS platform/i386-linux-gnu/xclang/include/*.h)
install(FILES ${HEADERS} DESTINATION ${PROJECT_BINARY_DIR}/InstallRoot/platform/i386-linux-gnu/xclang/include)
FILE(GLOB HEADERS platform/x86_64-linux-gnu/xclang/include/*.h)
install(FILES ${HEADERS} DESTINATION ${PROJECT_BINARY_DIR}/InstallRoot/platform/x86_64-linux-gnu/xclang/include)
FILE(GLOB HEADERS platform/arm-linux-gnueabi/xclang/include/*.h)
install(FILES ${HEADERS} DESTINATION ${PROJECT_BINARY_DIR}/InstallRoot/platform/arm-linux-gnueabi/xclang/include)
FILE(GLOB HEADERS platform/arm-linux-gnueabihf/xclang/include/*.h)
install(FILES ${HEADERS} DESTINATION ${PROJECT_BINARY_DIR}/InstallRoot/platform/arm-linux-gnueabihf/xclang/include)
FILE(GLOB HEADERS platform/aarch64-linux-gnu/xclang/include/*.h)
install(FILES ${HEADERS} DESTINATION ${PROJECT_BINARY_DIR}/InstallRoot/platform/aarch64-linux-gnu/xclang/include)




FILE(GLOB HEADERS platform/android/xclang/include/*.h)
install(FILES ${HEADERS} DESTINATION ${PROJECT_BINARY_DIR}/InstallRoot/platform/android-14/arch-arm/xclang/include)
install(FILES ${HEADERS} DESTINATION ${PROJECT_BINARY_DIR}/InstallRoot/platform/android-14/arch-mips/xclang/include)
install(FILES ${HEADERS} DESTINATION ${PROJECT_BINARY_DIR}/InstallRoot/platform/android-14/arch-x86/xclang/include)

#install(FILES ${HEADERS} DESTINATION ${PROJECT_BINARY_DIR}/InstallRoot/platform/android-9/arch-arm/xclang/include)
#install(FILES ${HEADERS} DESTINATION ${PROJECT_BINARY_DIR}/InstallRoot/platform/android-9/arch-mips/xclang/include)
#install(FILES ${HEADERS} DESTINATION ${PROJECT_BINARY_DIR}/InstallRoot/platform/android-9/arch-x86/xclang/include)




# install shell or bat.
if(WIN32)
	FILE(GLOB WIN_BAT bin/bat/*xclang*)
	message("${WIN_BAT}")
	install(FILES ${WIN_BAT} DESTINATION ${PROJECT_BINARY_DIR}/InstallRoot/bin)
	FILE(GLOB WIN_EXE bin/*.exe)
	message("${WIN_EXE}")
	install(FILES ${WIN_EXE} DESTINATION ${PROJECT_BINARY_DIR}/InstallRoot/bin)
else(WIN32)
	FILE(GLOB UNIX_SHELL bin/shell/*xclang*)
	install(FILES ${UNIX_SHELL} DESTINATION ${PROJECT_BINARY_DIR}/InstallRoot/bin 
		PERMISSIONS OWNER_READ GROUP_READ WORLD_READ OWNER_WRITE GROUP_WRITE WORLD_WRITE
		OWNER_EXECUTE GROUP_EXECUTE WORLD_EXECUTE
	 )
	FILE(GLOB UNIX_SHELL bin/shell/*xas*)
	install(FILES ${UNIX_SHELL} DESTINATION ${PROJECT_BINARY_DIR}/InstallRoot/bin 
		PERMISSIONS OWNER_READ GROUP_READ WORLD_READ OWNER_WRITE GROUP_WRITE WORLD_WRITE
		OWNER_EXECUTE GROUP_EXECUTE WORLD_EXECUTE
	 )
endif(WIN32)
