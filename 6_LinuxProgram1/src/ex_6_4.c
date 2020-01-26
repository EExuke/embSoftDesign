/**************************************************************************** **
 * Copyright (C) 2010-2011 Cameo Communications, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : ex_6_4.c
 *     FIRST CREATION DATE    : 2020/01/24
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/01/24
 *     FILE DESCRIPTION       : 试图打开一个不存在的文件，查看errno值的变化.
** ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>

/****************************************************************************
 *  Function Name : main
 *  Description   : The Main Function.
 *  Input(s)      : argc - The numbers of input value.
 *                : argv - The pointer to input specific parameters.
 *  Output(s)     : NULL
 *  Returns       : 0
 ****************************************************************************/
int main(int argc, const char *argv[])
{
	FILE * fp;
	errno = 0;
	fp = fopen("notexist", "r");
	if (errno)
	{
		printf("Open file failed.\n");
	}
	else
		printf("Open file successfully.\n");

	printf("try again:\n");
	errno = 0;
	fp = fopen("notexist", "w");
	if (errno)
	{
		printf("Open file failed.\n");
	}
	else
		printf("Open file successfully.\n");

    return 0;
}

