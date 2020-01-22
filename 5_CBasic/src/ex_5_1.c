/**************************************************************************** **
 * Copyright (C) 2010-2011 Cameo Communications, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : ex_5_1.c
 *     FIRST CREATION DATE    : 2020/01/21
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/01/21
 *     FILE DESCRIPTION       : 不带参数宏;
** ************************************************************************** */

#include <stdio.h>
#include "/home/xuke/bin/dbg.h"

#define A

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
#ifdef A
	printf("A has defined \n");
#else
	printf("A has not been defined \n");
#endif
    return 0;
}

