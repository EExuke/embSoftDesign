/**************************************************************************** **
 * Copyright (C) 2010-2011 Cameo Communications, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : ex_5_5.c
 *     FIRST CREATION DATE    : 2020/01/22
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/01/22
 *     FILE DESCRIPTION       : 头文件包含
** ************************************************************************** */

#include <stdio.h>
#include "/home/xuke/bin/dbg.h"
#include "../inc/ex_5_5.h"

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
	f();
    return 0;
}

/****************************************************************************
 *  Function Name : f
 *  Description   : The Function f().
 *  Input(s)      : NULL
 *                : NULL
 *  Output(s)     : NULL
 *  Returns       : 0
 ****************************************************************************/
void f()
{
	printf("a example of #include. \n");
}

