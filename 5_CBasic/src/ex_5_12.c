/**************************************************************************** **
 * Copyright (C) 2010-2011 Cameo Communications, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : ex_5_12.c
 *     FIRST CREATION DATE    : 2020/01/22
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/01/22
 *     FILE DESCRIPTION       : switch...case...简写
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
	int t = 2;
	/*传统方式*/
	switch(t)
	{
		case 0 :
		case 1 :
		case 2 :
			printf("012\n");
			break;
		case 3 :
		case 4 :
		case 5 :
			printf("345\n");
	}
	/*GCC扩展方式*/
	switch(t)
	{
		case 0 ... 2 :
			printf("012\n");
			break;
		case 3 ... 5 :
			printf("345\n");
	}
    return 0;
}

