/**************************************************************************** **
 * Copyright (C) 2010-2011 Cameo Communications, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : ex_6_21.c
 *     FIRST CREATION DATE    : 2020/01/25
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/01/25
 *     FILE DESCRIPTION       : pthread_create()、pthread_exit()和pthread_join()函数控制线程.
** ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include "../inc/ex_6_21.h"

/****************************************************************************
 *  Function Name : main
 *  Description   : The Main Function 演示了线程的创建、合并和终止.
 *  Input(s)      : argc - The numbers of input value.
 *                : argv - The pointer to input specific parameters.
 *  Output(s)     : NULL
 *  Returns       : 0
 ****************************************************************************/
int main()
{
	int res;
	pthread_t a_thread;
	void * thread_result;
	/* message作为字符串参数传递给thread_function */
	res = pthread_create(&a_thread, NULL, thread_function, (void * )message);
	if (res != 0)
	{
		perror("Thread creation failed.");
		exit(EXIT_FAILURE);
	}
	printf("Waiting for thread to finish... \n");
	res = pthread_join(a_thread, &thread_result);
	if(res != 0)
	{
		perror("Thread join failed.");
		exit(EXIT_FAILURE);
	}
	printf("Thread joined, it returned %s \n", (char * )thread_result);
	printf("Message is now %s \n", message);
	exit(EXIT_SUCCESS);
}

/****************************************************************************
 *  Function Name : thread_function
 *  Description   : The Function 显示被创建的线程运行状态.
 *  Input(s)      : arg 指向线程的入口函数.
 *                :
 *  Output(s)     : NULL
 *  Returns       : 0
 ****************************************************************************/
void * thread_function(void * arg)
{
	printf("thread_function is running. Argument was %s \n", (char * )arg);
	sleep(3);
	strcpy(message, "Bye!");
	pthread_exit("Thank you for CPU time. \n");
}
