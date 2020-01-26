/**************************************************************************** **
 * Copyright (C) 2010-2011 Cameo Communications, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : ex_6_12.c
 *     FIRST CREATION DATE    : 2020/01/24
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/01/24
 *     FILE DESCRIPTION       : getcwd()函数的使用.
** ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_NAME    100

/****************************************************************************
 *  Function Name : main
 *  Description   : The Main Function 调用getcwd()获取系统当前目录.
 *  Input(s)      : argc - The numbers of input value.
 *                : argv - The pointer to input specific parameters.
 *  Output(s)     : NULL
 *  Returns       : 0
 ****************************************************************************/
int main(int argc, const char *argv[])
{
	char dir[MAX_NAME];
	getcwd(dir, MAX_NAME);
	printf("系统当前工作目录为：%s \n", dir);
    return 0;
}

