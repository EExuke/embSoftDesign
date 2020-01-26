/**************************************************************************** **
 * Copyright (C) 2010-2011 Cameo Communications, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : ex_6_15.c
 *     FIRST CREATION DATE    : 2020/01/24
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/01/24
 *     FILE DESCRIPTION       : 通过结构体dirent、函数opendir()和readdir()获取和操作目录列表.
** ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>

/****************************************************************************
 *  Function Name : main
 *  Description   : The Main Function 显示当前目录下所有文件列表.
 *  Input(s)      : argc - The numbers of input value.
 *                : argv - The pointer to input specific parameters.
 *  Output(s)     : NULL
 *  Returns       : 0
 ****************************************************************************/
int main(int argc, const char *argv[])
{
	DIR * dir;
	struct dirent * list;

	dir = opendir("./");
	list = readdir(dir);
	printf("当前目录下文件列表为：\n");
	while(list != NULL)
	{
		printf("%s \n", list->d_name);
		/* 指向下一个节点的目录结构 */
		list = readdir(dir);
	}
	closedir(dir);
    return 0;
}

