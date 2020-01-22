/**************************************************************************** **
 * Copyright (C) 2010-2011 Cameo Communications, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : ex_5_4.c
 *     FIRST CREATION DATE    : 2020/01/22
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/01/22
 *     FILE DESCRIPTION       : 宏CAP控制条件编译
** ************************************************************************** */

#include <stdio.h>
#include "/home/xuke/bin/dbg.h"

#define CAP 1
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
	char string[20] = "I love China";
	char c;
	int i = 0;
	c = string[i++];
	while(c != '\0')
	{
#if CAP
		if ((c > 'a') && (c <'z'))
			c -= 32;
#endif
		printf("%c", c);
		c = string[i++];
	}
	printf("\n");
    return 0;
}

