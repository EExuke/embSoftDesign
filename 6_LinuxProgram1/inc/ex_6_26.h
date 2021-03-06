/**************************************************************************** **
 * Copyright (C) 2010-2011 Cameo Communications, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : ex_6_26.h
 *     FIRST CREATION DATE    : 2020/01/25
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/01/25
 *     FILE DESCRIPTION       : API exported to external moduels
** ************************************************************************** */
#ifndef _EX_6_26_H_
#define _EX_6_26_H_

/*------------------Macro Definition-------------------------*/
sem_t bin_sem;
#define WORK_SIZE    1024
char work_area[WORK_SIZE];

/*------------------End of Macro Definition------------------*/

/*------------------API Definition---------------------------*/
void * thread_function(void * arg);

/*------------------End of API Definition--------------------*/

#endif /* End of _EX_6_26_H_ */

