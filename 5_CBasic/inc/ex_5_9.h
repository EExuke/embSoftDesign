/**************************************************************************** **
 * Copyright (C) 2010-2011 Cameo Communications, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : ex_5_9.h
 *     FIRST CREATION DATE    : 2020/01/22
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/01/22
 *     FILE DESCRIPTION       : API exported to external moduels
** ************************************************************************** */
#ifndef _EX_5_9_H_
#define _EX_5_9_H_

/*------------------Macro Definition-------------------------*/
#define STEPLONG        0.1

/*------------------End of Macro Definition------------------*/

/*------------------API Definition---------------------------*/
double triangle(double( * func)(double), double begin, double end);
/*------------------End of API Definition--------------------*/

#endif /* End of _EX_5_9_H_ */

