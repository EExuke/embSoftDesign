
.PHONY: all
all: libmydll.so main

libmydll.so:
	gcc -shared -fPIC -o libmydll.so sub.c -Wall
#将libmydll.so移动到 /lib 路径中作为共享库：
	sudo mv libmydll.so /lib

main:
	gcc main.c -o main -lmydll -ldl -Wall

clean:
	sudo rm -f main /lib/libmydll.so
