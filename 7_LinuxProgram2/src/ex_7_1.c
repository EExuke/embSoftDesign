/**************************************************************************** **
 * Copyright (C) 2010-2011 Cameo Communications, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : ex_7_1.c
 *     FIRST CREATION DATE    : 2020/01/27
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/01/27
 *     FILE DESCRIPTION       : 信号处理函数signal().
** ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include "../inc/ex_7_1.h"

/****************************************************************************
 *  Function Name : main
 *  Description   : The Main Function 调用signal()函数处理信号.
 *                : SIGINT 为 Ctrl+C 的信号.
 *  Input(s)      :
 *  Output(s)     : NULL
 *  Returns       : 0
 ****************************************************************************/
int main()
{
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
 *  Description   : The Function 为接收到信号时的处理函数.
 *  Input(s)      : sig 为接受到的信号
 *                :
 *  Output(s)     : 重置信号响应为默认处理
 *  Returns       : NULL
 ****************************************************************************/
void sig_alarm(int sig)
{
	printf("---the signal received is %d. \n", sig);
	signal(SIGINT, SIG_DFL);
}

