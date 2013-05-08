set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR x86_64)
set(CMAKE_CROSSCOMPILING 1)
set(ROOT_XCLANG /Users/maeikei/workspace/xclang-dev/obj/InstallRoot)

set(CMAKE_C_COMPILER ${ROOT_XCLANG}/bin/x86_64-linux-gnu-xclang)
set(CMAKE_CXX_COMPILER ${ROOT_XCLANG}/bin/x86_64-linux-gnu-xclang++)
set(_CMAKE_TOOLCHAIN_PREFIX ${ROOT_XCLANG}/binutils/bin/x86_64-linux-gnu-)
