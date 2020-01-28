/**************************************************************************** **
 * Copyright (C) 2010-2011 Cameo Communications, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : ex_7_10.h
 *     FIRST CREATION DATE    : 2020/01/28
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/01/28
 *     FILE DESCRIPTION       : API exported to external moduels
** ************************************************************************** */
#ifndef _EX_7_10_H_
#define _EX_7_10_H_

/*------------------Macro Definition-------------------------*/
union semun
{
	int val;
	struct semid_ds * buf;
	unsigned short int * array;
	struct seminfo * __buf;
};

static int sem_id;

#define KEY_NAME    1234
#define P           1
#define V           -1

/*------------------End of Macro Definition------------------*/

/*------------------API Definition---------------------------*/
static void del_semvalue(void);
static int set_semvalue(void);
static int semaphore_p(void);
static int semaphore_v(void);

/*------------------End of API Definition--------------------*/

#endif /* End of _EX_7_10_H_ */

