/**************************************************************************** **
 * Copyright (C) 2010-2011 Cameo Communications, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : ex_7_3.c
 *     FIRST CREATION DATE    : 2020/01/27
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/01/27
 *     FILE DESCRIPTION       : alarm()函数发送信号,倒计时发送SIGALARM信号.
** ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

/****************************************************************************
 *  Function Name : main
 *  Description   : The Main Function 调用alarm()函数向自身发送信号.
 *  Input(s)      : NULL
 *                :
 *  Output(s)     : NULL
 *  Returns       : 0
 ****************************************************************************/
int main()
{
	int t;

	printf("alarm application starting. \n");
	/* 5秒后向自身发送SIGALARM信号，并执行默认操作(终止自身进程) */
	t = alarm(5);
	printf("t = %d \n", t);
	while(1)
	{
		printf("sleep 1s... \n");
		sleep(1);
	}
	printf("done. \n");
	exit(0);
}

