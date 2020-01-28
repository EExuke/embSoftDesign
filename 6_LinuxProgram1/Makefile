CFILES = src

.PHONY: all
all: ex_6_1 ex_6_2 ex_6_3 ex_6_4 ex_6_5 \
	 ex_6_6 ex_6_7 ex_6_8 ex_6_9 ex_6_10 \
	 ex_6_11 ex_6_12 ex_6_13 ex_6_14 ex_6_15 \
	 ex_6_16 ex_6_17 ex_6_18 ex_6_19 ex_6_20 \
	 ex_6_21 ex_6_22 ex_6_23 ex_6_24 ex_6_25 \
	 ex_6_26 ex_6_27 ex_6_28 ex_6_29 \
	 ${CFILES}/ex_6_30/libmy.a ex_6_30 \
	 ${CFILES}/ex_6_31/libmydll.so ex_6_31

ex_6_1: ${CFILES}/ex_6_1.c
	gcc ${CFILES}/ex_6_1.c -o ex_6_1
ex_6_2: ${CFILES}/ex_6_2.c
	gcc ${CFILES}/ex_6_2.c -o ex_6_2
ex_6_3: ${CFILES}/ex_6_3.c
	gcc ${CFILES}/ex_6_3.c -o ex_6_3
ex_6_4: ${CFILES}/ex_6_4.c
	gcc ${CFILES}/ex_6_4.c -o ex_6_4
ex_6_5: ${CFILES}/ex_6_5.c
	gcc ${CFILES}/ex_6_5.c -o ex_6_5
ex_6_6: ${CFILES}/ex_6_6.c
	gcc ${CFILES}/ex_6_6.c -o ex_6_6
ex_6_7: ${CFILES}/ex_6_7.c
	gcc ${CFILES}/ex_6_7.c -o ex_6_7
ex_6_8: ${CFILES}/ex_6_8.c
	gcc ${CFILES}/ex_6_8.c -o ex_6_8
ex_6_9: ${CFILES}/ex_6_9.c
	gcc ${CFILES}/ex_6_9.c -o ex_6_9
ex_6_10: ${CFILES}/ex_6_10.c
	gcc ${CFILES}/ex_6_10.c -o ex_6_10
ex_6_11: ${CFILES}/ex_6_11.c
	gcc ${CFILES}/ex_6_11.c -o ex_6_11
ex_6_12: ${CFILES}/ex_6_12.c
	gcc ${CFILES}/ex_6_12.c -o ex_6_12
ex_6_13: ${CFILES}/ex_6_13.c
	gcc ${CFILES}/ex_6_13.c -o ex_6_13
ex_6_14: ${CFILES}/ex_6_14.c
	gcc ${CFILES}/ex_6_14.c -o ex_6_14
ex_6_15: ${CFILES}/ex_6_15.c
	gcc ${CFILES}/ex_6_15.c -o ex_6_15
ex_6_16: ${CFILES}/ex_6_16.c
	gcc ${CFILES}/ex_6_16.c -o ex_6_16
ex_6_17: ${CFILES}/ex_6_17.c
	gcc ${CFILES}/ex_6_17.c -o ex_6_17
ex_6_18: ${CFILES}/ex_6_18.c
	gcc ${CFILES}/ex_6_18.c -o ex_6_18
ex_6_19: ${CFILES}/ex_6_19.c
	gcc ${CFILES}/ex_6_19.c -o ex_6_19
ex_6_20: ${CFILES}/ex_6_20.c
	gcc ${CFILES}/ex_6_20.c -o ex_6_20
#线程控制：
ex_6_21: ${CFILES}/ex_6_21.c
	gcc ${CFILES}/ex_6_21.c -pthread -o ex_6_21
ex_6_22: ${CFILES}/ex_6_22.c
	gcc ${CFILES}/ex_6_22.c -pthread -o ex_6_22
ex_6_23: ${CFILES}/ex_6_23.c
	gcc ${CFILES}/ex_6_23.c -pthread -o ex_6_23
ex_6_24: ${CFILES}/ex_6_24.c
	gcc ${CFILES}/ex_6_24.c -pthread -o ex_6_24
ex_6_25: ${CFILES}/ex_6_25.c
	gcc ${CFILES}/ex_6_25.c -pthread -o ex_6_25
ex_6_26: ${CFILES}/ex_6_26.c
	gcc ${CFILES}/ex_6_26.c -pthread -o ex_6_26
ex_6_27: ${CFILES}/ex_6_27.c
	gcc ${CFILES}/ex_6_27.c -pthread -o ex_6_27
ex_6_28: ${CFILES}/ex_6_28.c
	gcc ${CFILES}/ex_6_28.c -pthread -o ex_6_28
ex_6_29: ${CFILES}/ex_6_29.c
	gcc ${CFILES}/ex_6_29.c -pthread -o ex_6_29

#创建linux静态库
${CFILES}/ex_6_30/libmy.a: ${CFILES}/ex_6_30/hello.o ${CFILES}/ex_6_30/bye.o
	ar rc ${CFILES}/ex_6_30/libmy.a ${CFILES}/ex_6_30/hello.o ${CFILES}/ex_6_30/bye.o
${CFILES}/ex_6_30/hello.o: ${CFILES}/ex_6_30/hello.c
	gcc -c ${CFILES}/ex_6_30/hello.c -o ${CFILES}/ex_6_30/hello.o
${CFILES}/ex_6_30/bye.o: ${CFILES}/ex_6_30/bye.c
	gcc -c ${CFILES}/ex_6_30/bye.c -o ${CFILES}/ex_6_30/bye.o
ex_6_30: ${CFILES}/ex_6_30/main.c
	gcc ${CFILES}/ex_6_30/main.c -o ex_6_30 ${CFILES}/ex_6_30/libmy.a

#创建动态链接共享库
${CFILES}/ex_6_31/libmydll.so: ${CFILES}/ex_6_31/sub.c
	gcc -shared -fPIC -o ${CFILES}/ex_6_31/libmydll.so ${CFILES}/ex_6_31/sub.c -Wall
	sudo mv ${CFILES}/ex_6_31/libmydll.so /lib
ex_6_31: ${CFILES}/ex_6_31/main.c
	gcc ${CFILES}/ex_6_31/main.c -o ex_6_31 -lmydll -ldl -Wall

#目标文件移动到 ./obj 目录下
	mv ./ex_6_* ./obj/

clean:
	rm ./obj/ex_6_*
	rm ${CFILES}/ex_6_30/*.o ${CFILES}/ex_6_30/*.a
	sudo rm /lib/libmydll.so
