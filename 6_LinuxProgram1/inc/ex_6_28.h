/**************************************************************************** **
 * Copyright (C) 2010-2011 Cameo Communications, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : ex_6_28.h
 *     FIRST CREATION DATE    : 2020/01/26
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/01/26
 *     FILE DESCRIPTION       : API exported to external moduels
** ************************************************************************** */
#ifndef _EX_6_28_H_
#define _EX_6_28_H_

/*------------------Macro Definition-------------------------*/
char message[] = "Hello World";
int thread_finished = 0;

/*------------------End of Macro Definition------------------*/

/*------------------API Definition---------------------------*/
void * thread_function(void * arg);

/*------------------End of API Definition--------------------*/

#endif /* End of _EX_6_28_H_ */

