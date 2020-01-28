/**************************************************************************** **
 * Copyright (C) 2010-2011 Cameo Communications, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : ex_7_7.c
 *     FIRST CREATION DATE    : 2020/01/27
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/01/27
 *     FILE DESCRIPTION       : 1.sigismember()判断信号是否属于信号集; 2.sigpending()查看处于待处理状态的信号.
** ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "../inc/ex_7_7.h"

/****************************************************************************
 *  Function Name : main
 *  Description   : The Main Functioni 演示调用sigismember()和sigpending()函数.
 *  Input(s)      : NULL
 *                :
 *  Output(s)     : NULL
 *  Returns       : 0
 ****************************************************************************/
int main(int argc, const char *argv[])
{
	sigset_t seta;
	sigset_t setb;
	int t;

	/* 初始化一个满集合(包含所有信号) */
	sigfillset(&seta);
	signal(SIGINT, wake);
	/* 设置屏蔽字为 seta集合 */
	sigprocmask(SIG_SETMASK, &seta, NULL);
	printf("sleep 5s. Never send the 9th sig. \n");
	/* 睡眠5秒，此时进程屏蔽所有信号 */
	sleep(5);
	/* 取消对 SIGINT 信号的屏蔽 */
	sigdelset(&seta, SIGINT);
	printf("wake up now! \n");
	/* 返回当前进程中待处理的信号集 */
	sigpending(&setb);
	/* 判断SIGINT信号是否在setb信号集中 */
	t = sigismember(&setb, SIGINT);
	printf("t = %d \n", t);
	printf("I will sigsuspend! \n");
	/* 挂起，改变屏蔽信号集 */
	sigsuspend(&seta);
	printf("returned from the handler. sleep 5s now. You can press Ctrl+C \n");
	sleep(5);
	printf("Reaching the end! \n");
    return 0;
}

/****************************************************************************
 *  Function Name : wake
 *  Description   : The Functioni is 信号处理函数 
 *  Input(s)      : NULL
 *                :
 *  Output(s)     : NULL
 *  Returns       : NULL
 ****************************************************************************/
void wake()
{
	puts("entering wake. ");
	signal(SIGINT, wake);
	puts("leaving wake");
	return;
}

