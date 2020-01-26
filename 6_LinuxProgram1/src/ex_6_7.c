/**************************************************************************** **
 * Copyright (C) 2010-2011 Cameo Communications, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : ex_6_7.c
 *     FIRST CREATION DATE    : 2020/01/24
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/01/24
 *     FILE DESCRIPTION       : strerror()函数获取错误信息，perror()函数输出系统错误信息.
** ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <math.h>

/****************************************************************************
 *  Function Name : main
 *  Description   : The Main Function 试图以读模式打开一个并不存在的文件.
 *  Input(s)      : argc - The numbers of input value.
 *                : argv - The pointer to input specific parameters.
 *  Output(s)     : NULL
 *  Returns       : 0
 ****************************************************************************/
int main(int argc, const char *argv[])
{
	FILE * fp;
	char * p;

	errno = 0;
	fp = fopen("notexist", "r");
	if (errno)
		perror("Open file");

	errno = 0;
	fp = fopen("notexist", "r");
	if (errno)
	{
		p = strerror(errno);
		fprintf(stderr, "Open file: %s \n", p);
	}
    return 0;
}

