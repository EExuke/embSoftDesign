/**************************************************************************** **
 * Copyright (C) 2010-2011 Cameo Communications, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : ex_7_4.c
 *     FIRST CREATION DATE    : 2020/01/27
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/01/27
 *     FILE DESCRIPTION       : sigaction()函数，并使用SA_RESETHAND重置为默认操作来处理 Ctrl+C 信号.
** ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "../inc/ex_7_4.h"

/****************************************************************************
 *  Function Name : main
 *  Description   : The Main Function.
 *  Input(s)      : NULL
 *                :
 *  Output(s)     : NULL
 *  Returns       : NULL
 ****************************************************************************/
int main()
{
	struct sigaction act;

	act.sa_handler = sig_alarm;
	sigemptyset(&act.sa_mask);
	/* 将信号处理函数重置为默认值 */
	act.sa_flags = SA_RESETHAND;
	sigaction(SIGINT, &act, 0);
	while(1)
	{
		printf("waiting here! \n");
		sleep(1);
	}
}

/****************************************************************************
 *  Function Name : sig_alarm
 *  Description   : The Function 信号处理函数.
 *  Input(s)      : sig 接受到的信号
 *                :
 *  Output(s)     : NULL
 *  Returns       : NULL
 ****************************************************************************/
void sig_alarm(int sig)
{
	printf("---the signal received is %d. \n", sig);
}

