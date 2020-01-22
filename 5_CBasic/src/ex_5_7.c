/**************************************************************************** **
 * Copyright (C) 2010-2011 Cameo Communications, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : ex_5_7.c
 *     FIRST CREATION DATE    : 2020/01/22
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/01/22
 *     FILE DESCRIPTION       : 用按位异或，实现不通过中间变量而交换两变量的值
** ************************************************************************** */

#include <stdio.h>
#include "/home/xuke/bin/dbg.h"

/****************************************************************************
 *  Function Name : main
 *  Description   : The Main Function.
 *  Input(s)      : a
 *                : b
 *  Output(s)     : NULL
 *  Returns       : 0
 ****************************************************************************/
int main(int argc, char *argv[])
{
	int a, b;
	a = 21;
	b = 43;
	printf("before exchange: a=%d, b=%d\n", a, b);
	a = a^b;
	b = b^a;
	a = a^b;
	printf("after exchange: a=%d, b=%d\n", a, b);
    return 0;
}

