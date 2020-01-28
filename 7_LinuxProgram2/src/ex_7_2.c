/**************************************************************************** **
 * Copyright (C) 2010-2011 Cameo Communications, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : ex_7_2.c
 *     FIRST CREATION DATE    : 2020/01/27
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/01/27
 *     FILE DESCRIPTION       : kill()信号发送函数.
** ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include "../inc/ex_7_2.h"

/****************************************************************************
 *  Function Name : main
 *  Description   : The Main Function 调用kill()函数向进程发送信号.
 *  Input(s)      : NULL
 *                :
 *  Output(s)     : NULL
 *  Returns       : 0
 ****************************************************************************/
int main()
{
	int pid;
	printf("alarm application starting. \n");
	/* 子进程 */
	if ((pid = fork()) == 0)
	{
		sleep(5);
		/* 向父进程发送SIGALRM信号 */
		kill(getppid(), SIGALRM);
		exit(0);
	}
	printf("waiting for alarm to go off... \n");
	signal(SIGALRM, ding);
	/* 挂起父进程，等待异步信号被接受并处理 */
	pause();
	if (alarm_fired)
	{
		printf("Ding! \n");
	}
	printf("done. \n");
	exit(0);
}

/****************************************************************************
 *  Function Name : ding
 *  Description   : The Function 是信号处理函数.
 *  Input(s)      : sig 接收到的等待处理的信号.
 *                :
 *  Output(s)     : NULL
 *  Returns       : NULL
 ****************************************************************************/
void ding(int sig)
{
	alarm_fired = 1;
}

