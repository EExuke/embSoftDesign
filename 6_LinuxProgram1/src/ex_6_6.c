/**************************************************************************** **
 * Copyright (C) 2010-2011 Cameo Communications, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : ex_6_6.c
 *     FIRST CREATION DATE    : 2020/01/24
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/01/24
 *     FILE DESCRIPTION       : exit()函数终止程序和atexit()函数注册终止函数的使用.
** ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../inc/ex_6_6.h"

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
	printf("Hello everybody. \n");
	/* 注册终止函数，成功返回0，否则返回1. */
	if (atexit(test) != 0)
	{
		printf("atexit() run failed. \n");
		exit(EXIT_FAILURE);
	}
	printf("goodbye everybody. \n");
    return 0;
}

/****************************************************************************
 *  Function Name : test
 *  Description   : The test Function 是被atexit()注册的终止函数，会在程序结束之前被调用，
 *                ：即被exit()调用，或者被main()函数返回时调用.
 *  Input(s)      : NULL
 *                :
 *  Output(s)     : NULL
 *  Returns       : 0
 ****************************************************************************/
void test()
{
	printf("you can still get here. \n");
}
