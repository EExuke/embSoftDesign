/**************************************************************************** **
 * Copyright (C) 2010-2011 Cameo Communications, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : ex_6_29.c
 *     FIRST CREATION DATE    : 2020/01/26
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/01/26
 *     FILE DESCRIPTION       : pthread_cancel()实现线程取消;pthread_setcancelstate()设置取消状态;
 *                            ：pthread_setcanceltype()设置取消类型.
** ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include "../inc/ex_6_29.h"

/****************************************************************************
 *  Function Name : main
 *  Description   : The Main Function 作为初始线程，创建和回收具有线程取消行为的子线程.
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
	res = pthread_create(&a_thread, NULL, thread_function, NULL);
	if (res != 0)
	{
		perror("Thread creation failed");
		exit(EXIT_FAILURE);
	}
	sleep(3);
	printf("Canceling thread... \n");
	/* 取消线程 a_thread */
	res = pthread_cancel(a_thread);
	if (res != 0)
	{
		perror("Thread Cancelation failed");
		exit(EXIT_FAILURE);
	}
	printf("Waiting for thread to finish... \n");
	/* 调用pthread_join()合并并结束子线程，即制造“可取消点” */
	res = pthread_join(a_thread, &thread_result);
	if (res != 0)
	{
		perror("Thread join failed");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

/****************************************************************************
 *  Function Name : thread_function
 *  Description   : The Function 作为具有线程取消行为的子线程.
 *  Input(s)      : arg 初始线程传递的参数.
 *                :
 *  Output(s)     : NULL
 *  Returns       : 0
 ****************************************************************************/
void * thread_function(void * arg)
{
	int i, res, j;
	/* 设置取消状态为允许态 */
	res = pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
	if (res != 0)
	{
		perror("Thread pthread_setcancelstate failed");
		exit(EXIT_FAILURE);
	}
	/* 设置取消类型为到达“可取消点”时取消 */
	res = pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL);
	if (res != 0)
	{
		perror("Thread pthread_setcanceltype failed");
		exit(EXIT_FAILURE);
	}
	printf("thread_function is running. \n");
	/* 由于线程取消，10次循环并不会执行完毕 */
	for (i=0; i<10; i++)
	{
		printf("Thread is still running (%d)... \n", i);
		sleep(1);
	}
	pthread_exit(0);
}
