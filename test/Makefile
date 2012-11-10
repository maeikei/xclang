XCLANG_PATH = /Users/maeikei/workspace/xclang-dev/obj/InstallRoot/bin
CC = $(XCLANG_PATH)/x86_64-pc-linux-gnueabi-xclang
CXX = $(XCLANG_PATH)/x86_64-pc-linux-gnueabi-xclang++
all:
	$(CC) main.c -o /tmp/main.c.o
	$(CC) main.c -c -o /tmp/main.c.o
	$(CC) main.c -c
	$(CXX) main.cpp -o /tmp/main.cpp.o
clean:
	rm -f *.o
