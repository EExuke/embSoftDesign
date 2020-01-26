/**************************************************************************** **
 * Copyright (C) 2010-2011 Cameo Communications, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : ex_6_10.c
 *     FIRST CREATION DATE    : 2020/01/24
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/01/24
 *     FILE DESCRIPTION       : fread()函数读取文件内容.
** ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../inc/ex_6_10.h"

/****************************************************************************
 *  Function Name : main
 *  Description   : The Main Function 调用fread()函数读取文件内容.
 *  Input(s)      : argc - The numbers of input value.
 *                : argv - The pointer to input specific parameters.
 *  Output(s)     : NULL
 *  Returns       : 0
 ****************************************************************************/
int main(int argc, const char *argv[])
{
	FILE * stream;
	stream = fopen("test", "r");
	fread(a, block_lenth, block_num, stream);
	fclose(stream);
	a[MAX_LEN] = '\0';
	printf("a = %s \n", a);
    return 0;
}

