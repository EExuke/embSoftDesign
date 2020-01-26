# 动态链接库
# 创建的动态库可以只放在当前路径使用：
gcc -shared -fPIC -o libmydll.so sub.c -Wall

# 也可以将创建好的库文件移动到 /usr/lib 下共用：
mv libmydll.so /lib
gcc main.c -o main -lmydll -ldl -Wall
