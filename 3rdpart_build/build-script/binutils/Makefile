target += i686-w64-mingw32
target += x86_64-w64-mingw32

target += x86_64-pc-linux-gnueabi

#target += x86_64-apple-darwin



SRC   := binutils-2.23.1
install :=$(shell pwd)/install/binutils



MKDIR := mkdir
MAKE  := make
CD    := cd


.PHONY: targets $(target)

all:$(target)

$(target):
	$(MKDIR) -p ./objects/$@
	$(CD) ./objects/$@;../../$(SRC)/configure --target=$@ --prefix=$(install)
	$(MAKE) -C ./objects/$@ all install
