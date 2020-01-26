/**************************************************************************** **
 * Copyright (C) 2010-2011 Cameo Communications, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : sub.c
 *     FIRST CREATION DATE    : 2020/01/26
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/01/26
 *     FILE DESCRIPTION       : 动态链接库
** ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

/****************************************************************************
 *  Function Name : square
 *  Description   : The Function 被main.c调用.
 *  Input(s)      : a main函数传递的int型参数.
 *                :
 *  Output(s)     : 提示语句.
 *  Returns       : a的平方.
 ****************************************************************************/
int square(int a)
{
	printf("the square of the number is:");
    return (a * a);
}

