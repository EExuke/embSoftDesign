/**************************************************************************** **
 * Copyright (C) 2010-2011 Cameo Communications, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : ex_6_21.h
 *     FIRST CREATION DATE    : 2020/01/25
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/01/25
 *     FILE DESCRIPTION       : API exported to external moduels
** ************************************************************************** */
#ifndef _EX_6_21_H_
#define _EX_6_21_H_

/*------------------Macro Definition-------------------------*/
char message[] = "Hello World";

/*------------------End of Macro Definition------------------*/

/*------------------API Definition---------------------------*/
void * thread_function(void * arg);

/*------------------End of API Definition--------------------*/

#endif /* End of _EX_6_21_H_ */

