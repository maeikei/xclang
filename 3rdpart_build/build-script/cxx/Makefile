#target += i686-w64-mingw32
#target += x86_64-w64-mingw32

target += i386-linux-gnu
#target += x86_64-linux-gnu
#target += arm-linux-gnueabi
#target += arm-linux-gnueabihf


PWD     := $(shell pwd)
SRC     := $(PWD)/libcxx
install := $(PWD)/install
RTSRC   := $(PWD)/../cxxrt/libcxxrt



MKDIR := mkdir
MAKE  := make
CD    := cd
RM    := rm

CROSS_ROOT  := /Users/maeikei/workspace/xclang-dev/obj/InstallRoot/

.PHONY: $(target)

all:$(target)

$(target):
	$(MKDIR) -p ./objects/$@
	-$(CD) ./objects/$@ &&\
		cmake $(SRC) -DCMAKE_TOOLCHAIN_FILE=$(PWD)/../$@.cmake\
		-DLIBCXX_CXX_ABI=libcxxrt\
		-DLIBCXX_LIBCXXRT_INCLUDE_PATHS="$(RTSRC)/src"\
		-DLIBCXX_ENABLE_SHARED=0\
		-DCMAKE_INSTALL_PREFIX=$(install)
	$(MAKE) -C ./objects/$@ all -j4
	$(MAKE) -C ./objects/$@ install

clean:
	$(RM) -rf objects
	$(RM) -rf $(install)


