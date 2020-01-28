/**************************************************************************** **
 * Copyright (C) 2010-2011 Cameo Communications, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : ex_7_10.c
 *     FIRST CREATION DATE    : 2020/01/28
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/01/28
 *     FILE DESCRIPTION       : semget()获取信号量、semop()改变信号量、semctl()控制信号量.
** ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include "../inc/ex_7_10.h"

/****************************************************************************
 *  Function Name : main
 *  Description   : The Main Function.
 *  Input(s)      : argc - The numbers of input value.
 *                : argv - The pointer to input specific parameters.
 *  Output(s)     : NULL
 *  Returns       : 0
 ****************************************************************************/
int main(int argc, const char *argv[])
{
	int i;
	int pause_time;
	char op_char = 'O';

	srand((unsigned int)getpid());
	sem_id = semget((key_t)KEY_NAME, 1, 0666 | IPC_CREAT);
	/* 如果进程有参数，初始化信号量，并将本进程的字符修改为'X' */
	if (argc > 1)
	{
		if (!set_semvalue())
		{
			fprintf(stderr, "Failed to initialize semaphore. \n");
			exit(EXIT_FAILURE);
		}
		op_char = 'X';
		sleep(5);
	}
	/* 输出字符 */
	for (i = 0; i < 10; i++)
	{
		/* 执行P操作 */
		if (!semaphore_p())
			exit(EXIT_FAILURE);
		printf("%c", op_char);
		fflush(stdout);
		pause_time = (rand() % 3);
		sleep(pause_time);
		printf("%c", op_char);
		fflush(stdout);
		/* 执行V操作 */
		if (!semaphore_v())
			exit(EXIT_FAILURE);
		pause_time = (rand() % 2);
		sleep(pause_time);
	}
	printf("\n%d - finished. \n", getpid());
	/* 如果进程有参数，挂起10秒，删除信号量 */
	if (argc > 1)
	{
		sleep(10);
		del_semvalue();
	}
	exit(EXIT_SUCCESS);
}

/****************************************************************************
 *  Function Name : del_semvalue
 *  Description   : The Function 删除信号量.
 *  Input(s)      : NULL
 *                :
 *  Output(s)     : NULL
 *  Returns       : 0
 ****************************************************************************/
static void del_semvalue(void)
{
	union semun sem_union;
	if (semctl(sem_id, 0, IPC_RMID, sem_union) == -1)
		fprintf(stderr, "Failed to delete semaphore. \n");
}

/****************************************************************************
 *  Function Name : set_semvalue
 *  Description   : The Function 将信号量初始化为1.
 *  Input(s)      : NULL
 *                :
 *  Output(s)     : NULL
 *  Returns       : 失败返回0，成功返回1.
 ****************************************************************************/
static int set_semvalue(void)
{
	union semun sem_union;
	sem_union.val = 1;
	if (semctl(sem_id, 0, SETVAL, sem_union) == -1)
		return(0);
	return(1);
}

/****************************************************************************
 *  Function Name : semaphore_p
 *  Description   : The Function 执行P操作.
 *  Input(s)      : NULL
 *                :
 *  Output(s)     : NULL
 *  Returns       : 失败返回0，成功返回1.
 ****************************************************************************/
static int semaphore_p(void)
{
	struct sembuf sem_b;
	sem_b.sem_num = 0;
	sem_b.sem_op = P;
	sem_b.sem_flg = SEM_UNDO;

	if (semop(sem_id, &sem_b, 1) == -1)
	{
		fprintf(stderr, "semaphore_p failed. \n");
		return(0);
	}
	return(1);
}

/****************************************************************************
 *  Function Name : semaphore_v
 *  Description   : The Function 执行V操作.
 *  Input(s)      : NULL
 *                :
 *  Output(s)     : NULL
 *  Returns       : 失败返回0，成功返回1.
 ****************************************************************************/
static int semaphore_v(void)
{
	struct sembuf sem_b;
	sem_b.sem_num = 0;
	sem_b.sem_op = V;
	sem_b.sem_flg = SEM_UNDO;

	if (semop(sem_id, &sem_b, 1) == -1)
	{
		fprintf(stderr, "semaphore_v failed. \n");
		return(0);
	}
	return(1);
}

