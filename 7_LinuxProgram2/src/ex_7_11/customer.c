/**************************************************************************** **
 * Copyright (C) 2010-2011 Cameo Communications, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : customer.c
 *     FIRST CREATION DATE    : 2020/01/28
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/01/28
 *     FILE DESCRIPTION       : 生产者——消费者使用共享内存实现进程间通信.
 *                            ：shmget()获取共享内存、shmat()连接共享内存、shmdt()取消连接、shmctl()控制共享内存.
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
 *  Description   : The Main Function is 消费者程序.
 *  Input(s)      : NULL
 *                :
 *  Output(s)     : NULL
 *  Returns       : 0
 ****************************************************************************/
int main()
{
	int running = 1;
	void * shared_memory = (void * )0;
	struct shared_use_st * shared_stuff;
	int shmid;

	srand((unsigned int)getpid());
	/* 创建一个共享内存并的到标识符 */
	shmid = shmget((key_t)SHM_NAME, sizeof(struct shared_use_st), 0666 | IPC_CREAT);
	if (shmid == -1)
	{
		fprintf(stderr, "shmget failed. \n");
		exit(EXIT_FAILURE);
	}
	/* 将当前进程连接该共享内存 */
	shared_memory = shmat(shmid, (void *)0, 0);
	if (shared_memory == (void *)-1)
	{
		fprintf(stderr, "shmat failed. \n");
		exit(EXIT_FAILURE);
	}
	printf("Memory attached at %X \n", (int)shared_memory);
	shared_stuff = (struct shared_use_st *)shared_memory;
	shared_stuff->written_by_you = 0;
	while(running)
	{
		/* 如果生产者已经写入数据，则读取数据 */
		if (shared_stuff->written_by_you)
		{
			printf("You wrote: %s \n", shared_stuff->some_text);
			sleep(rand() % 4);
			shared_stuff->written_by_you = 0;
			if (strncmp(shared_stuff->some_text, "end", 3) == 0)
			{
				running = 0;
			}
		}
	}
	/* 取消本进程空间与共享内存的连接 */
	if (shmdt(shared_memory) == -1)
	{
		fprintf(stderr, "shmdt failed. \n");
		exit(EXIT_FAILURE);
	}
	/* 销毁创建的共享内存 */
	if (shmctl(shmid, IPC_RMID, 0) == -1)
	{
		fprintf(stderr, "shmctl failed. \n");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

