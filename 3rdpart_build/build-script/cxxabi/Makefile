#target += i686-w64-mingw32
#target += x86_64-w64-mingw32

#target += i386-linux-gnu
#target += x86_64-linux-gnu
#target += arm-linux-gnueabi
target += arm-linux-gnueabihf


PWD     := $(shell pwd)
SRC     := $(PWD)/libcxxabi
install := $(PWD)/install



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
		-DLIBCXX_ENABLE_SHARED=OFF\
		-DCMAKE_BUILD_TYPE=Debug\
		-DCMAKE_INSTALL_PREFIX=$(CROSS_ROOT)/platform/$@/cxx
	$(MAKE) -C ./objects/$@ all -j4
	$(MAKE) -C ./objects/$@ install
	$(RM) -rf ./objects/$@
	$(MKDIR) -p ./objects/$@
	-$(CD) ./objects/$@ &&\
		cmake $(SRC) -DCMAKE_TOOLCHAIN_FILE=$(PWD)/../$@.cmake\
		-DLIBCXX_ENABLE_SHARED=ON\
		-DCMAKE_BUILD_TYPE=Debug\
		-DCMAKE_INSTALL_PREFIX=$(CROSS_ROOT)/platform/$@/cxx
	$(MAKE) -C ./objects/$@ all -j4
	$(MAKE) -C ./objects/$@ install

clean:
	$(RM) -rf objects
	$(RM) -rf $(install)


