/**************************************************************************** **
 * Copyright (C) 2010-2011 Cameo Communications, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : ex_6_3.c
 *     FIRST CREATION DATE    : 2020/01/23
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/01/23
 *     FILE DESCRIPTION       : 预定义宏__LINE__和__FILE__的使用
** ************************************************************************** */

#include <stdio.h>
#include "/home/xuke/bin/dbg.h"
#include <stdlib.h>
#include "../inc/ex_6_3.h"

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
	char * e1 = "HOME";
	char * e2 = "NOTEXIST";
	int res;
	res = show_environment(e1, __LINE__, __FILE__);
	if (res)
		return 1;
	res = show_environment(e2, __LINE__, __FILE__);
	if (res)
		return 1;
    return 0;
}

/****************************************************************************
 *  Function Name : show_environment
 *  Description   : The Function show the ENVIRONMENT.
 *  Input(s)      : e:环境目录
 *                : num:行号
 *                : name:文件名
 *  Output(s)     : NULL
 *  Returns       : 0 or 1
 ****************************************************************************/
int show_environment(char * e, int num, char * name)
{
	char * p = getenv(e);
	if (p != NULL)
	{
		printf("the environment is: %s\n", p);
		return 0;
	}
	else
	{
		printf("error occured at %d of %s.\n", num, name);
		return 1;
	}
}
