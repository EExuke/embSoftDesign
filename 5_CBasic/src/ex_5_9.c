/**************************************************************************** **
 * Copyright (C) 2010-2011 Cameo Communications, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : ex_5_9.c
 *     FIRST CREATION DATE    : 2020/01/22
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/01/22
 *     FILE DESCRIPTION       : 以0.1为步长，计算特定范围内的三角函数之和
** ************************************************************************** */

#include <stdio.h>
#include "/home/xuke/bin/dbg.h"
#include <math.h>
#include "../inc/ex_5_9.h"

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
	double result;
	/*对于math.h,编译时需要带 -lm 参数，即："gcc file.c -lm -o file" */
	result = triangle(sin, 0.1, 1.0);
	printf("the sum of sin from 0.1 to 1.0 is %f\n", result);
	result = triangle(cos, 0.5, 3.0);
	printf("the sum of cos from 0.1 to 1.0 is %f\n", result);
	result = triangle(tan, 0.1, 1.0);
	printf("the sum of tan from 0.1 to 1.0 is %f\n", result);
    return 0;
}

/****************************************************************************
 *  Function Name : triangle
 *  Description   : The Function 计算特定范围内的三角函数之和。
 *  Input(s)      : *func 为三角函数函数指针
 *                : begin 为范围头
 *                : end 为范围尾
 *  Output(s)     : NULL
 *  Returns       : sum 范围内三角函数之和，步长为0.1
 ****************************************************************************/
double triangle(double( * func)(double), double begin, double end)
{
	double step, sum = 0.0;

	for(step = begin; step < end ; step += STEPLONG)
		sum += func(step);
	return sum;
}
