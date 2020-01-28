/**************************************************************************** **
 * Copyright (C) 2010-2011 Cameo Communications, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : ex_7_6.c
 *     FIRST CREATION DATE    : 2020/01/27
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/01/27
 *     FILE DESCRIPTION       : 信号集处理函数的使用.
** ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "../inc/ex_7_6.h"

/****************************************************************************
 *  Function Name : main
 *  Description   : The Main Function 调用sigprocmask()函数将set中的信号添加到信号屏蔽字中.
 *  Input(s)      : NULL
 *                :
 *  Output(s)     : NULL
 *  Returns       : 0
 ****************************************************************************/
int main()
{
	sigset_t * set;
	sigset_t * oldset;
	
	/* 初始化信号集set为空 */
	sigemptyset(set);
	/* 将SIGINT信号添加到信号集set */
	sigaddset(set, SIGINT);
	/* 将信号集set添加到信号屏蔽字 */
	sigprocmask(SIG_BLOCK, set, oldset);
	signal(SIGINT, sig_alarm);
	while(1)
	{
		printf("waiting here! \n");
		sleep(1);
	}
    return 0;
}

/****************************************************************************
 *  Function Name : sig_alarm
 *  Description   : The Function is 信号集处理函数 
 *  Input(s)      : sig 为接受的信号
 *                :
 *  Output(s)     : NULL
 *  Returns       : NULL
 ****************************************************************************/
void sig_alarm(int sig)
{
	printf("---the signal received is %d. \n", sig);
	signal(SIGINT, SIG_DFL);
}
