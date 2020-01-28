/**************************************************************************** **
 * Copyright (C) 2010-2011 Cameo Communications, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : producer.c
 *     FIRST CREATION DATE    : 2020/01/28
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/01/28
 *     FILE DESCRIPTION       : 生产者——消费者使用共享内存实现进程间通信.
 *                            : shmget()获取共享内存、shmat()连接共享内存、shmdt()取消连接、shmctl()控制共享内存.
** ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "../../inc/ex_7_11.h"

/****************************************************************************
 *  Function Name : main
 *  Description   : The Main Function is 生产者程序.
 *  Input(s)      : argc - The numbers of input value.
 *                : argv - The pointer to input specific parameters.
 *  Output(s)     : NULL
 *  Returns       : 0
 ****************************************************************************/
int main(int argc, const char *argv[])
{
	int running = 1;
	void * shared_memory = (void * )0x0101;
	struct shared_use_st * shared_stuff;
	int shmid;
	char buffer[BUFSIZ];

	/* 得到消费者创建的共享内存的标识符 */
	shmid = shmget((key_t)SHM_NAME, sizeof(struct shared_use_st), 0666 | IPC_CREAT);
	if (shmid == -1)
	{
		fprintf(stderr, "shmget failed. \n");
		exit(EXIT_FAILURE);
	}
	/* 连接该共享内存 */
	shared_memory = shmat(shmid, (void *)0, 0);
	if (shared_memory == (void *)-1)
	{
		fprintf(stderr, "shmat failed. \n");
		exit(EXIT_SUCCESS);
	}
	printf("Memory attached at %X \n", (int)shared_memory);
	shared_stuff = (struct shared_use_st *)shared_memory;
	while(running)
	{
		/* 等待消费者输出完成，并将 written_by_you 清零*/
		if (shared_stuff->written_by_you == 1)
		{
			sleep(1);
			printf("waiting for client... \n");
		}
		printf("Enter some text: ");
		fgets(buffer, BUFSIZ, stdin);
		strncpy(shared_stuff->some_text, buffer, TEXT_SZ);
		shared_stuff->written_by_you = 1;
		if (strncmp(buffer, "end", 3) == 0)
		{
			running = 0;
		}
	}
	/* 取消本进程与共享内存的连接 */
	if (shmdt(shared_memory) == -1)
	{
		fprintf(stderr, "shmdt failed. \n");
		exit(EXIT_FAILURE);
	}
	printf("producer exit. \n");
	exit(EXIT_SUCCESS);
}

