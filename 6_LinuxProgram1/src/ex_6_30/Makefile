Object = obj

.PHONY: all
all: libmy.a main

libmy.a: hello.o bye.o
	ar rc libmy.a hello.o bye.o
hello.o: hello.c
	gcc -c hello.c -o hello.o
bye.o: bye.c
	gcc -c bye.c -o bye.o
main: main.c
	gcc main.c -o main libmy.a

clean:
	rm *.o main *.a
