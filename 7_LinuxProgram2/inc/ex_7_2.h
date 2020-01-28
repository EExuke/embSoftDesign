/**************************************************************************** **
 * Copyright (C) 2010-2011 Cameo Communications, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : ex_7_2.h
 *     FIRST CREATION DATE    : 2020/01/27
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/01/27
 *     FILE DESCRIPTION       : API exported to external moduels
** ************************************************************************** */
#ifndef _EX_7_2_H_
#define _EX_7_2_H_

/*------------------Macro Definition-------------------------*/
static int alarm_fired = 0;

/*------------------End of Macro Definition------------------*/

/*------------------API Definition---------------------------*/
void ding(int sig);

/*------------------End of API Definition--------------------*/

#endif /* End of _EX_7_2_H_ */

