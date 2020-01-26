/**************************************************************************** **
 * Copyright (C) 2010-2011 Cameo Communications, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : ex_6_26.c
 *     FIRST CREATION DATE    : 2020/01/25
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/01/25
 *     FILE DESCRIPTION       : 用信号量同步线程.
** ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
#include "../inc/ex_6_26.h"

/****************************************************************************
 *  Function Name : main
 *  Description   : The Main Function 调用sem信号量协调线程的同步.
 *  Input(s)      : argc - The numbers of input value.
 *                : argv - The pointer to input specific parameters.
 *  Output(s)     : NULL
 *  Returns       : 0
 ****************************************************************************/
int main(int argc, const char *argv[])
{
	int res;
	pthread_t a_thread;
	void * thread_result;

	/* 将信号量初始化为0 */
	res = sem_init(&bin_sem, 0, 0);
	if (res != 0)
	{
		perror("Semaphore initialization failed");
		exit(EXIT_FAILURE);
	}
	res = pthread_create(&a_thread, NULL, thread_function, NULL);
	if (res != 0)
	{
		perror("Thread create failed.");
		exit(EXIT_FAILURE);
	}
	printf("Input some text. Enter 'end' to finish. \n");
	/* 判断是否是终止字符串end */
	while(strncmp("end", work_area, 3) != 0)
	{
		/* 将标准输入内容放在work_area中 */
		fgets(work_area, WORK_SIZE, stdin);
		/* 信号量加1 */
		sem_post(&bin_sem);
	}
	printf("\n Waiting for thread to finish... \n");
	/* 执行结束后合并线程 */
	res = pthread_join(a_thread, &thread_result);
	if (res != 0)
	{
		perror("Thread join failed");
		exit(EXIT_FAILURE);
	}
	printf("Thread joined.\n");
	/* 注销信号量 */
	sem_destroy(&bin_sem);
	exit(EXIT_SUCCESS);
}

/****************************************************************************
 *  Function Name : thread_function
 *  Description   : The Function 代表子进程.
 *  Input(s)      : argc - The numbers of input value.
 *                : argv - The pointer to input specific parameters.
 *  Output(s)     : NULL
 *  Returns       : 0
 ****************************************************************************/
void * thread_function(void * arg)
{
	sem_wait(&bin_sem);
	while(strncmp("end", work_area, 3) != 0)
	{
		printf("You input %d characters. \n", strlen(work_area) - 1);
		sem_wait(&bin_sem);
	}
	pthread_exit(NULL);
}
