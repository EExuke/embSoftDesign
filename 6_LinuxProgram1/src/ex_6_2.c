/**************************************************************************** **
 * Copyright (C) 2010-2011 Cameo Communications, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : ex_6_1.c
 *     FIRST CREATION DATE    : 2020/01/23
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/01/23
 *     FILE DESCRIPTION       : 定义宏开关NDEBUG，控制是否使用assert测试表达式结果正确性
** ************************************************************************** */
#define NDEBUG
#include <stdio.h>
#include "/home/xuke/bin/dbg.h"
#include <assert.h>
#include <stdlib.h>

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
	char * p;
	p = getenv("HOME");
	assert(p);
	printf("HOME = %s\n", p);
	p = getenv("NOTEXIST");
	assert(p);
	printf("NOTEXIST = %s\n", p);
    return 0;
}

