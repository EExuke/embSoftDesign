/**************************************************************************** **
 * Copyright (C) 2010-2011 Cameo Communications, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : ex_7_11.h
 *     FIRST CREATION DATE    : 2020/01/28
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/01/28
 *     FILE DESCRIPTION       : API exported to external moduels
** ************************************************************************** */
#ifndef _EX_7_11_H_
#define _EX_7_11_H_

/*------------------Macro Definition-------------------------*/
#define TEXT_SZ    2048    //共享内存容量
#define SHM_NAME   1234

struct shared_use_st
{
	int written_by_you;
	char some_text[TEXT_SZ];
};

/*------------------End of Macro Definition------------------*/

/*------------------API Definition---------------------------*/
/*------------------End of API Definition--------------------*/

#endif /* End of _EX_7_11_H_ */

