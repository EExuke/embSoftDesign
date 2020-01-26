/**************************************************************************** **
 * Copyright (C) 2010-2011 Cameo Communications, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : ex_6_18.c
 *     FIRST CREATION DATE    : 2020/01/25
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/01/25
 *     FILE DESCRIPTION       : exec()函数簇替换替换进程空间的程序代码.
** ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/****************************************************************************
 *  Function Name : main
 *  Description   : The Main Function 调用execve()函数簇替换替换进程空间的程序代码为date.
 *  Input(s)      : argc - The numbers of input value.
 *                : argv - The pointer to input specific parameters.
 *  Output(s)     : NULL
 *  Returns       : 0
 ****************************************************************************/
int main(void)
{
	char * argv[] = {"/bin/date", NULL};
	if (execve("/bin/date", argv, NULL) == -1)
	{
		printf("execve execute error!");
		exit(EXIT_FAILURE);
	}
	printf("will not signal here.\n");
    return 0;
}

