/**************************************************************************** **
 * Copyright (C) 2010-2011 Cameo Communications, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : ex_5_11.c
 *     FIRST CREATION DATE    : 2020/01/22
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/01/22
 *     FILE DESCRIPTION       : 设置__attribute__的aligned(alignment)属性,可改变
 *                              结构体成员的最小对齐格式，以字节为单位.
** ************************************************************************** */

#include <stdio.h>
#include "/home/xuke/bin/dbg.h"
#include <stdlib.h>

struct s
{
	int a[2] __attribute__ ((aligned(8)));
};

struct t
{
	char a;
	int b[2] __attribute__ ((packed));
};

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
	int y __attribute__ ((aligned(16)));
	y = 1;
    return 0;
}

