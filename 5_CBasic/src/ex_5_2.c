/**************************************************************************** **
 * Copyright (C) 2010-2011 Cameo Communications, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : ex_5_2.c
 *     FIRST CREATION DATE    : 2020/01/21
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/01/21
 *     FILE DESCRIPTION       : 带参数宏
** ************************************************************************** */

#include <stdio.h>
#include "/home/xuke/bin/dbg.h"

#define FUNC(a, b)    ((a)>(b)?(a):(b))

/****************************************************************************
 *  Function Name : func
 *  Description   : The Function return lower value.
 *  Input(s)      : a
 *                : b
 *  Output(s)     : the lower one in a and b.
 *  Returns       : lower value
 ****************************************************************************/
int func(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

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
	int p = FUNC(3, 2);
	int q = func(3, 2);
	if (p == q)
		printf("equal!\n");
	return 0;
}

