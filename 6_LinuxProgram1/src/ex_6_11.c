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
 *     FILE DESCRIPTION       : fwrite()函数写入文件内容.
** ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../inc/ex_6_11.h"

/****************************************************************************
 *  Function Name : main
 *  Description   : The Main Function 调用fwrite()函数写入文件内容.
 *  Input(s)      : argc - The numbers of input value.
 *                : argv - The pointer to input specific parameters.
 *  Output(s)     : NULL
 *  Returns       : 0
 ****************************************************************************/
int main(int argc, const char *argv[])
{
	FILE * stream;
	/* 写入文件内容 */
	sprintf(name, "just a test. \n");
	stream = fopen("test", "w");
	fwrite(name, block_lenth, block_num, stream);
	fclose(stream);

	return 0;
}

