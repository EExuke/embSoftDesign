/**************************************************************************** **
 * Copyright (C) 2010-2011 Cameo Communications, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : ex_7_12.h
 *     FIRST CREATION DATE    : 2020/01/28
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/01/28
 *     FILE DESCRIPTION       : API exported to external moduels
** ************************************************************************** */
#ifndef _EX_7_12_H_
#define _EX_7_12_H_

/*------------------Macro Definition-------------------------*/
#define MAX_TEXT    512
#define MSG_NAME    1234

struct my_msg
{
	long int my_msg_type;
	char some_text[BUFSIZ];
};

struct my_msg_snd
{
	long int my_msg_type;
	char some_text[MAX_TEXT];
};

/*------------------End of Macro Definition------------------*/

/*------------------API Definition---------------------------*/
/*------------------End of API Definition--------------------*/

#endif /* End of _EX_7_12_H_ */

