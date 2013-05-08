XCLANG_PATH = /Users/maeikei/workspace/xclang-dev/obj/InstallRoot/bin

#target += x86_64-w64-mingw32
#target += arm-linux-androideabi

#target += i386-linux-gnu
target += x86_64-linux-gnu
#target += arm-linux-gnueabi
#target += arm-linux-gnueabihf

.PHONY: $(target)

all:$(target)

$(target):
	$(XCLANG_PATH)/$@-xclang sub.c main.c -L./ -L ../ -I./ -I ../  -o main.out
	$(XCLANG_PATH)/$@-xclang sub.c main.c
	$(XCLANG_PATH)/$@-xclang main.c -c -o main.c.o
	$(XCLANG_PATH)/$@-xclang sub.c main.c -c
	$(XCLANG_PATH)/$@-xclang sub.c main.c -S
#	$(XCLANG_PATH)/$@-xclang sub.c main.c -E
	$(XCLANG_PATH)/$@-xclang++ main.cpp -L./ -L ../ -I./ -I ../ -S -o main.cpp.clang.s
	$(XCLANG_PATH)/$@-xclang++ main.cpp -g -L./ -L ../ -I./ -I ../ -o main.cpp.out


clean:
	rm -f *.o *.s *.out *.exe *.obj
