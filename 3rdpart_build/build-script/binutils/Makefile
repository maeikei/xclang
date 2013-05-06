target += i686-w64-mingw32
target += x86_64-w64-mingw32

target += i386-linux-gnu
target += x86_64-linux-gnu
target += arm-linux-gnueabi
target += arm-linux-gnueabihf

#target += arm-linux-androideabi
#target += mipsel-linux-android
#target += i686-linux-android


SRC   := binutils-2.23.1
install :=$(shell pwd)/install/binutils


SYSROOT :=/Users/maeikei/workspace/xclang-dev/obj/InstallRoot/platform

MKDIR := mkdir
MAKE  := make
CD    := cd
RM    := rm


.PHONY: $(target)

all:$(target)

$(target):
	$(MKDIR) -p ./objects/$@
	$(CD) ./objects/$@;../../$(SRC)/configure --target=$@ --prefix=$(install)\
		--with-build-sysroot=$(SYSROOT)/$@
	$(MAKE) -C ./objects/$@ all -j4
	$(MAKE) -C ./objects/$@ install

clean:
	$(RM) -rf objects
	$(RM) -rf $(install)
