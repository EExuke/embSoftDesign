/**************************************************************************** **
 * Copyright (C) 2010-2011 Cameo Communications, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : ex_6_17.c
 *     FIRST CREATION DATE    : 2020/01/25
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/01/25
 *     FILE DESCRIPTION       : 通过system()函数使用shell命令.
** ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

/****************************************************************************
 *  Function Name : main
 *  Description   : The Main Function 调用system()函数使用shell命令ls.
 *  Input(s)      : argc - The numbers of input value.
 *                : argv - The pointer to input specific parameters.
 *  Output(s)     : NULL
 *  Returns       : 0
 ****************************************************************************/
int main(int argc, const char *argv[])
{
	system("ls -al /bin");
    return 0;
}

