/**************************************************************************** **
 * Copyright (C) 2010-2011 Cameo Communications, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : ex_7_8.c
 *     FIRST CREATION DATE    : 2020/01/27
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/01/27
 *     FILE DESCRIPTION       : 无名管道的用法:pipe()创建管道、read()和write()读写管道、close()关闭管道.
** ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "../inc/ex_7_8.h"

/****************************************************************************
 *  Function Name : main
 *  Description   : The Main Function 使用无名管道与子进程通信.
 *  Input(s)      : NULL
 *                :
 *  Output(s)     : char[] 向无名管道写入信息.
 *  Returns       : 0
 ****************************************************************************/
int main()
{
	int fd[PIPE_NAME_LEN];
	int pid;

	/* 创建无名管道 */
	if ((pipe(fd)) < 0)
	{
		printf("pipe error happended! \n");
		exit(EXIT_FAILURE);
	}
	/* 创建子进程 */
	pid = fork();
	if (pid < 0)
	{
		printf("process error happended! \n");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		char out[TEXT_MAX_LEN];
		/* 读时关闭写 */
		close(fd[PIPE_WRITE]);
		read(fd[PIPE_READ], out, TEXT_MAX_LEN);
		/* 打印输出 */
		printf("%s", out);
		close(fd[PIPE_READ]);
		exit(EXIT_SUCCESS);
	}
	else
	{
		char buf[TEXT_MAX_LEN] = "this is a test of pipe! \n";
		/* 写时关闭读 */
		close(fd[PIPE_READ]);
		write(fd[PIPE_WRITE], buf, TEXT_MAX_LEN);
		close(fd[PIPE_WRITE]);
		wait(NULL);
	}
    return 0;
}

