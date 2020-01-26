/**************************************************************************** **
 * Copyright (C) 2010-2011 Cameo Communications, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : main.c
 *     FIRST CREATION DATE    : 2020/01/26
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/01/26
 *     FILE DESCRIPTION       : dlopen()打开共享库、dlsym()提取函数地址、dlclose()关闭共享库、
 *                            ：dlerror()共享库错误函数.
** ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "sub.h"

/****************************************************************************
 *  Function Name : main
 *  Description   : The Main Function 调用sub.c共享库.
 *  Input(s)      :
 *                :
 *  Output(s)     : NULL
 *  Returns       : 0
 ****************************************************************************/
int main()
{
	void * handle;
	int (* fp)(int);
	char * error;
	int n;
	int result;
	printf("please input a number. \n");
	scanf("%d", &n);

	/* 打开共享库，以RTLD_LAZY方式 */
	handle = dlopen("/lib/libmydll.so", RTLD_LAZY);
	if (!handle)
	{
		printf("%s \n", error);
	}
	/* 提取库中的函数square() */
	fp = dlsym(handle, "square");
	if ((error = dlerror()) != NULL)
	{
		printf("%s \n", error);
		dlclose(handle);
		exit(1);
	}
	printf("now call the function square. \n");
	result = (* fp)(n);    //使用提取的函数，并传入参数n
	printf(" %d \n", result);
	dlclose(handle);
    return 0;
}

