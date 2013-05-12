target += i686-w64-mingw32
target += x86_64-w64-mingw32

SRC   := mingw-w64/trunk
install :=$(shell pwd)/install/unwind


#CROSS_ROOT  := /Users/maeikei/workspace/xclang-dev/obj/InstallRoot/
CROSS_ROOT  := /home/ma/workspace/xclang-dev/obj/InstallRoot/

MKDIR := mkdir
MAKE  := make
CD    := cd
RM    := rm


.PHONY: $(target)

all:$(target)

$(target):
	$(MKDIR) -p ./objects/$@
	$(CD) $(SRC) && autoreconf -i
	$(CD) ./objects/$@&&\
	../../$(SRC)/configure --target=$@ --prefix=$(CROSS_ROOT)/platform/$@ \
	--disable-shared \
	--with-gnu-ar=$(CROSS_ROOT)/binutils/$@/bin/ar \
	CC=$(CROSS_ROOT)/bin/$@-xclang CXX=$(CROSS_ROOT)/bin/$@-xclang++ 
	$(MAKE) -C ./objects/$@ all -j4
	$(MAKE) -C ./objects/$@ install

clean:
	$(RM) -rf objects
	$(RM) -rf $(install)
