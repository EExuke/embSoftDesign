/**************************************************************************** **
 * Copyright (C) 2010-2011 Cameo Communications, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : ex_6_25.c
 *     FIRST CREATION DATE    : 2020/01/25
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/01/25
 *     FILE DESCRIPTION       : 初始线程打印1,子线程打印2,演示线程的并发性.
** ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include "../inc/ex_6_25.h"

/****************************************************************************
 *  Function Name : main
 *  Description   : The Main Functioni 创建线程，并与线程并发执行.
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
	int print_count1 = 0;

	res = pthread_create(&a_thread, NULL, thread_function, (void * )message);
	if (res != 0)
	{
		perror("Thread creation failed.");
		exit(EXIT_FAILURE);
	}
	while(print_count1++ < 20)
	{
		if (run_now == 1)
		{
			printf("1 \n");
			run_now = 2;
		}
		else
			sleep(1);
	}
	/* 等待线程结束 */
	printf("\n Waiting ofr thread to finish... \n");
	res = pthread_join(a_thread, &thread_result);
	if(res != 0)
	{
		perror("Thread join failed.");
		exit(EXIT_FAILURE);
	}
	printf("Thread joined. \n");
	exit(EXIT_SUCCESS);
}

/****************************************************************************
 *  Function Name : thread_function
 *  Description   : The thread Functioni .
 *  Input(s)      : argc - The numbers of input value.
 *                : argv - The pointer to input specific parameters.
 *  Output(s)     : NULL
 *  Returns       : 0
 ****************************************************************************/
void * thread_function(void * arg)
{
	int print_count2 = 0;
	while(print_count2++ < 20)
	{
		if (run_now == 2)
		{
			printf("2 \n");
			run_now = 1;
		}
		else
			sleep(1);
	}
	sleep(3);
}
