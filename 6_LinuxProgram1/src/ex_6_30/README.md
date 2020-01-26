# 创建静态库
#创建的库可以只放在当前路径使用：
gcc -c hello.c -o hello.o
gcc -c bye.c -o bye.o
ar rc libmy.a hello.o bye.o    //参数c代表创建归档文件，r代表把后续若干文件插入到归档文件中;
gcc main.c -o main ./libmy.a

#也可以将创建好的库文件移动到 /usr/lib 下共用：
mv libmy.a /usr/lib/
gcc main.c -o main -lmy
