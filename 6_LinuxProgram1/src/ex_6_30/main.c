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
 *     FILE DESCRIPTION       : 调用库函数的主函数main
** ************************************************************************** */


/****************************************************************************
 *  Function Name : main
 *  Description   : The Main Function 调用自定义的库函数.
 *  Input(s)      : argc - The numbers of input value.
 *                : argv - The pointer to input specific parameters.
 *  Output(s)     : NULL
 *  Returns       : 0
 ****************************************************************************/
int main()
{
	hello();
	bye();
    return 0;
}

