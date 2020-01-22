/**************************************************************************** **
 * Copyright (C) 2010-2011 Cameo Communications, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : ex_5_13.c
 *     FIRST CREATION DATE    : 2020/01/22
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/01/22
 *     FILE DESCRIPTION       : GCC预定义宏__FUNCTION__的使用.
** ************************************************************************** */

#include <stdio.h>
#include "/home/xuke/bin/dbg.h"
#include "../inc/ex_5_13.h"

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
	printf("This is function %s \n", __FUNCTION__);
	f();
    return 0;
}

/****************************************************************************
 *  Function Name : f
 *  Description   : The Function f().
 *  Input(s)      : 
 *                : 
 *  Output(s)     : NULL
 *  Returns       : 0
 ****************************************************************************/
void f(void)
{
	printf("This is function %s \n", __FUNCTION__);
}

