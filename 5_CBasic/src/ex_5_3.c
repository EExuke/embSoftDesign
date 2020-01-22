/**************************************************************************** **
 * Copyright (C) 2010-2011 Cameo Communications, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : ex_5_3.c
 *     FIRST CREATION DATE    : 2020/01/22
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/01/22
 *     FILE DESCRIPTION       : C89规定的5个预定义宏
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
	printf("the current file is %s\n", __FILE__);
	printf("the current line number is: %d\n", __LINE__);
	printf("today is: %s\n", __DATE__);
	printf("the time is: %s now\n", __TIME__);
	if (__STDC__ == 1)
		printf("This is a standard compiler\n");
	else if (__STDC__ == 0)
		printf("This is not a standard compiler\n");
	return 0;
}

