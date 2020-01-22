/**************************************************************************** **
 * Copyright (C) 2010-2011 Cameo Communications, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : ex_5_8.c
 *     FIRST CREATION DATE    : 2020/01/22
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/01/22
 *     FILE DESCRIPTION       : 32位数循环右移n位
** ************************************************************************** */

#include <stdio.h>
#include "/home/xuke/bin/dbg.h"

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
	unsigned a, b, c, n;
	scanf("a=%x,n=%d\n", &a, &n);
	b = a << (32-n);
	c = a >> n;
	c = c | b;
	printf("a=%x, c=%x\n", a, c);
    return 0;
}

