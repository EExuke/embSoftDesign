/**************************************************************************** **
 * Copyright (C) 2010-2011 Cameo Communications, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : ex_6_19.c
 *     FIRST CREATION DATE    : 2020/01/25
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/01/25
 *     FILE DESCRIPTION       : wait()函数和相关宏，等待进程结束.
** ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/****************************************************************************
 *  Function Name : main
 *  Description   : The Main Function 调用wait()和相关宏等待进程结束.
 *  Input(s)      : argc - The numbers of input value.
 *                : argv - The pointer to input specific parameters.
 *  Output(s)     : NULL
 *  Returns       : 0
 ****************************************************************************/
int main(int argc, const char *argv[])
{
	int s;
	pid_t id,retvalue;

	id = fork();
	if (id < 0)
	{
		printf("something is wrong! \n");
		exit(EXIT_FAILURE);
	}
	else if (id == 0)
	{
		printf("child process %d started \n", getpid());
		sleep(3);
		exit(100);
	}
	else
	{
		/* wait的参数用于收集子进程返回信息 */
		retvalue = wait(&s);
		/* WIFEXITED根据s分析子进程退出状态，正常返回非0值，否则返回0 */
		if (WIFEXITED(s))
		{
			printf("the child process %d exit normally. \n", retvalue);
			printf("the return code is %d. \n", WEXITSTATUS(s));
		}
		else
			printf("the child process %d exit abnormally. \n", retvalue);
	}

    return 0;
}

