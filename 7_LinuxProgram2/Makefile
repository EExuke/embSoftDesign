CFILES = src
TARGET =  ex_7_1 ex_7_2 ex_7_3 ex_7_4 ex_7_5 \
	      ex_7_6 ex_7_7 ex_7_8 ex_7_9 ex_7_10 \
	      ex_7_11_C ex_7_11_P \
	      ex_7_12_R ex_7_12_S

.PHONY: all
all: ${TARGET}

ex_7_1: ${CFILES}/ex_7_1.c
	gcc ${CFILES}/ex_7_1.c -o ex_7_1
ex_7_2: ${CFILES}/ex_7_2.c
	gcc ${CFILES}/ex_7_2.c -o ex_7_2
ex_7_3: ${CFILES}/ex_7_3.c
	gcc ${CFILES}/ex_7_3.c -o ex_7_3
ex_7_4: ${CFILES}/ex_7_4.c
	gcc ${CFILES}/ex_7_4.c -o ex_7_4
ex_7_5: ${CFILES}/ex_7_5.c
	gcc ${CFILES}/ex_7_5.c -o ex_7_5
ex_7_6: ${CFILES}/ex_7_6.c
	gcc ${CFILES}/ex_7_6.c -o ex_7_6
ex_7_7: ${CFILES}/ex_7_7.c
	gcc ${CFILES}/ex_7_7.c -o ex_7_7
ex_7_8: ${CFILES}/ex_7_8.c
	gcc ${CFILES}/ex_7_8.c -o ex_7_8
ex_7_9: ${CFILES}/ex_7_9.c
	gcc ${CFILES}/ex_7_9.c -o ex_7_9
ex_7_10: ${CFILES}/ex_7_10.c
	gcc ${CFILES}/ex_7_10.c -o ex_7_10
#生产消费者模式
ex_7_11_C: ${CFILES}/ex_7_11/customer.c
	gcc ${CFILES}/ex_7_11/customer.c -o ex_7_11_C
ex_7_11_P: ${CFILES}/ex_7_11/producer.c
	gcc ${CFILES}/ex_7_11/producer.c -o ex_7_11_P
#消息队列接收
ex_7_12_R: ${CFILES}/ex_7_12/receive.c
	gcc ${CFILES}/ex_7_12/receive.c -o ex_7_12_R
ex_7_12_S: ${CFILES}/ex_7_12/send.c
	gcc ${CFILES}/ex_7_12/send.c -o ex_7_12_S

#目标文件移至 ./obj 目录下
	mv ./ex_7_* ./obj

clean:
	rm ./obj/ex_7_*
