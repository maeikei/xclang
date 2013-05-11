target += i686-w64-mingw32
target += x86_64-w64-mingw32

target += i386-linux-gnu
target += x86_64-linux-gnu
target += arm-linux-gnueabi
target += arm-linux-gnueabihf
target += aarch64-linux-gnu

#target += arm-linux-androideabi
#target += mipsel-linux-android
#target += i686-linux-android


SRC   := binutils-2.23.2
install :=$(shell pwd)/install/binutils


CROSS_ROOT  := /Users/maeikei/workspace/xclang-dev/obj/InstallRoot/
#CROSS_ROOT  := /home/ma/workspace/xclang-dev/obj/InstallRoot/

MKDIR := mkdir
MAKE  := make
CD    := cd
RM    := rm


.PHONY: $(target)

all:$(target)

$(target):
	$(MKDIR) -p ./objects/$@
	$(CD) ./objects/$@;../../$(SRC)/configure --target=$@ --prefix=$(CROSS_ROOT)/binutils\
		--with-build-sysroot=$(CROSS_ROOT)/platform/$@\
		--with-sysroot=$(CROSS_ROOT)/platform/$@
	$(MAKE) -C ./objects/$@ all -j4
	$(MAKE) -C ./objects/$@ install

clean:
	$(RM) -rf objects
	$(RM) -rf $(install)
