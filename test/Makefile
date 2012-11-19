XCLANG_PATH = /Users/maeikei/workspace/xclang-dev/obj/InstallRoot/bin
CC = $(XCLANG_PATH)/x86_64-pc-linux-gnueabi-xclang
CXX = $(XCLANG_PATH)/x86_64-pc-linux-gnueabi-xclang++
all:
	$(CC) sub.c main.c -o /tmp/main.c.o
	$(CC) main.c -c -o /tmp/main.c.o
	$(CC) sub.c main.c -c
	$(CC) sub.c main.c -S
	$(CC) sub.c main.c -E
#	$(CXX) main.cpp -o /tmp/main.cpp.o
clean:
	rm -f *.o *.s
