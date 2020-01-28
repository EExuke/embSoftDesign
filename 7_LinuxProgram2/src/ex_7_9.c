/**************************************************************************** **
 * Copyright (C) 2010-2011 Cameo Communications, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : ex_7_9.c
 *     FIRST CREATION DATE    : 2020/01/28
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/01/28
 *     FILE DESCRIPTION       : mkfifo()函数创建有名管道.
** ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

/****************************************************************************
 *  Function Name : main
 *  Description   : The Main Function 调用mkfifo()创建有名管道.
 *  Input(s)      : argc - The numbers of input value.
 *                : argv - The pointer to input specific parameters.
 *  Output(s)     : NULL
 *  Returns       : 0
 ****************************************************************************/
int main(int argc, const char *argv[])
{
	/* 以777权限创建有名管道，名字为argv[1] */
	if ((mkfifo(argv[1], 0777)) < 0)
	{
		printf("fifo make error! \n");
		exit(EXIT_FAILURE);
	}
	printf("succeed. \n");
    return 0;
}

