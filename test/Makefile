XCLANG_PATH = /Users/maeikei/workspace/xclang-dev/obj/InstallRoot/bin
CC = $(XCLANG_PATH)/x86_64-w64-mingw32-xclang
CXX = $(XCLANG_PATH)/x86_64-w64-mingw32-xclang++
all:
	$(CC) sub.c main.c -L./ -L ../ -I./ -I ../  -o main.out
	$(CC) sub.c main.c
	$(CC) main.c -c -o main.c.o
	$(CC) sub.c main.c -c
	$(CC) sub.c main.c -S
#	$(CC) sub.c main.c -E
	$(CXX) main.cpp -L./ -L ../ -I./ -I ../ -S -o main.cpp.clang.s
	$(CXX) main.cpp -L./ -L ../ -I./ -I ../ -o main.cpp.o
clean:
	rm -f *.o *.s *.out *.exe
