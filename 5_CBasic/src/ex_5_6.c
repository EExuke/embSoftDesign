/**************************************************************************** **
 * Copyright (C) 2010-2011 Cameo Communications, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : ex_5_6.c
 *     FIRST CREATION DATE    : 2020/01/22
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/01/22
 *     FILE DESCRIPTION       : 预定义处理指令 #error
** ************************************************************************** */

#include <stdio.h>
#include "/home/xuke/bin/dbg.h"
#include "../inc/ex_5_6.h"

/****************************************************************************
 *  Function Name : main
 *  Description   : The Main Function, 编译到某一条 #error指令时，会停止编译，
 *  				同时显示对应的错误信息
 *  Input(s)      : NULL
 *                : 
 *  Output(s)     : NULL
 *  Returns       : 0
 ****************************************************************************/
int main(int argc, const char *argv[])
{
#if CON1
	#if CON2
		#error run to position1
	#else
		#error run to position2
	#endif
#else
	#if CON3
		#error run to position3
	#else
		#error run to position4
	#endif
#endif
    return 0;
}

