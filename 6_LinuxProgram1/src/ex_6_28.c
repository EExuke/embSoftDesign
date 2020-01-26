/**************************************************************************** **
 * Copyright (C) 2010-2011 Cameo Communications, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : ex_6_28.c
 *     FIRST CREATION DATE    : 2020/01/26
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/01/26
 *     FILE DESCRIPTION       : 线程属性对象的创建和分离线程的方法.
** ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include "../inc/ex_6_28.h"

/****************************************************************************
 *  Function Name : main
 *  Description   : The Main Functioni 调用pthread_attr_init()创建线程的属性对象;
 *                ：调用pthread_attr_setdetachstate()设置分离属性,即可不需要合并而自动回收.
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
	pthread_attr_t thread_attr;

	res = pthread_attr_init(&thread_attr);
	if (res != 0)\
	{
		perror("Attribute creation failed");
		exit(EXIT_FAILURE);
	}
	/* 设置分离属性 */
	res = pthread_attr_setdetachstate(&thread_attr, PTHREAD_CREATE_DETACHED);
	if (res != 0)
	{
		perror("Setting detached attribute failed");
		exit(EXIT_FAILURE);
	}
	/* 创建具有分离属性的新线程 */
	res = pthread_create(&a_thread, &thread_attr, thread_function, (void * )message);
	if (res != 0)
	{
		perror("Thread creation failed");
		exit(EXIT_FAILURE);
	}
	(void)pthread_attr_destroy(&thread_attr);
	/* 判断新线程是否结束 */
	while(!thread_finished)
	{
		printf("Waiting for thread to say it's finished... \n");
		sleep(1);
	}
	printf("Other thread finished, bye! \n");
	exit(EXIT_SUCCESS);
}

/****************************************************************************
 *  Function Name : thread_function
 *  Description   : The Functioni 打印显示线程运行状态.
 *                ：
 *  Input(s)      : arg 初始线程传递的参数.
 *                : 
 *  Output(s)     : NULL
 *  Returns       : 0
 ****************************************************************************/
void * thread_function(void * arg)
{
	printf("thread_function is running. Argument was %s \n", (char * )arg);
	sleep(4);
	printf("Second thread setting finished flag, and exiting now. \n");
	thread_finished = 1;
	pthread_exit(NULL);
}

