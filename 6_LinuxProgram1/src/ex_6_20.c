/**************************************************************************** **
 * Copyright (C) 2010-2011 Cameo Communications, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : ex_6_20.c
 *     FIRST CREATION DATE    : 2020/01/25
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/01/25
 *     FILE DESCRIPTION       : waitpid()函数，等待指定进程结束.
** ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/****************************************************************************
 *  Function Name : main
 *  Description   : The Main Function 调用waitpid()函数等待指定进程结束.
 *  Input(s)      : argc - The numbers of input value.
 *                : argv - The pointer to input specific parameters.
 *  Output(s)     : NULL
 *  Returns       : 0
 ****************************************************************************/
int main(int argc, const char *argv[])
{
	pid_t pid, cpid;
	int status;

	pid = fork();
	if (-1 == pid)
	{
		printf("fork error! \n");
		exit(EXIT_FAILURE);
	}
	else if (0 == pid)
	{
		printf("in child \n");
		printf("child pid is %d \n", getpid());
		printf("parent pid is %d \n", getppid());
		sleep(1);
		printf("child process is to exit. \n");
		exit(0);
	}
	else
	{
		printf("in parent \n");
		cpid = waitpid(pid, &status, WNOHANG);
		/* 等待子进程结束，返回非0值 */
		while(0 == cpid)
		{
			printf("waiting... \n");
			usleep(300000);
			cpid = waitpid(pid, &status, WNOHANG);
		}
		printf("parent pid is %d \n", getpid());
		printf("child exited with the code %d \n", status >> 8);
		printf("child pid is %d \n", cpid);
	}

    return 0;
}

