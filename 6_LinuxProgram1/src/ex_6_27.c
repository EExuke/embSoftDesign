/**************************************************************************** **
 * Copyright (C) 2010-2011 Cameo Communications, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : ex_6_27.c
 *     FIRST CREATION DATE    : 2020/01/26
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/01/26
 *     FILE DESCRIPTION       : pthread_mutex_互斥量同步线程
** ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <string.h>
#include "../inc/ex_6_27.h"

/****************************************************************************
 *  Function Name : main
 *  Description   : The Main Function 使用互斥锁同步线程.
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
	
	/* 初始化互斥量 */
	res = pthread_mutex_init(&work_mutex, NULL);
	if (res != 0)
	{
		perror("Mutex initialization failed.");
		exit(EXIT_FAILURE);
	}
	/* 创建线程 */
	res = pthread_create(&a_thread, NULL, thread_function, NULL);
	if (res != 0)
	{
		perror("Thread create failed.");
		exit(EXIT_FAILURE);
	}
	pthread_mutex_lock(&work_mutex);
	printf("Input some text. Enter 'end' to finish. \n");
	while(!time_to_exit)
	{
		fgets(work_area, WORK_SIZE, stdin);
		pthread_mutex_unlock(&work_mutex);
		while(1)
		{
			pthread_mutex_lock(&work_mutex);
			/* 判断数据是否已被读取 */
			if (work_area[0] != '\0')
			{
				pthread_mutex_unlock(&work_mutex);
				sleep(1);
			}
			else
				break;
		}
	}
	/* 解锁 */
	pthread_mutex_unlock(&work_mutex);
	printf("\nWaiting for thread to finish... \n");
	res = pthread_join(a_thread, &thread_result);
	if (res != 0)
	{
		perror("Thread join faild.");
		exit(EXIT_FAILURE);
	}
	printf("Thread joined. \n");
	/* 删除互斥量 */
	pthread_mutex_destroy(&work_mutex);
	exit(EXIT_SUCCESS);
}

/****************************************************************************
 *  Function Name : thread_function
 *  Description   : The Function 打印输入的字符.
 *  Input(s)      : arg 初始线程传递来的参数.
 *  Output(s)     : NULL
 *  Returns       : 0
 ****************************************************************************/
void * thread_function(void * arg)
{
	sleep(1);
	/* 互斥量加锁 */
	pthread_mutex_lock(&work_mutex);
	/* 判断是否是终止字符串“end” */
	while(strncmp("end", work_area, 3) != 0)
	{
		printf("You input %ld characters \n", strlen(work_area) - 1);
		work_area[0] = '\0';
		/* 互斥量解锁 */
		pthread_mutex_unlock(&work_mutex);
		sleep(1);
		pthread_mutex_lock(&work_mutex);
		/* 每隔一秒判断一次是否写入了数据 */
		while(work_area[0] == '\0')
		{
			pthread_mutex_unlock(&work_mutex);
			sleep(1);
			pthread_mutex_lock(&work_mutex);
		}
	}
	time_to_exit = 1;
	work_area[0] = '\0';
	pthread_mutex_unlock(&work_mutex);
	pthread_exit(0);
}

