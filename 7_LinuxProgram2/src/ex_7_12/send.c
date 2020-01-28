/**************************************************************************** **
 * Copyright (C) 2010-2011 Cameo Communications, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : send.c
 *     FIRST CREATION DATE    : 2020/01/28
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/01/28
 *     FILE DESCRIPTION       : 消息队列——发送者.
** ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include "../../inc/ex_7_12.h"

/****************************************************************************
 *  Function Name : main
 *  Description   : The Main Function 使用消息队列发送消息.
 *  Input(s)      : NULL
 *                :
 *  Output(s)     : NULL
 *  Returns       : 0
 ****************************************************************************/
int main()
{
	int running = 1;
	int msgid;
	struct my_msg_snd some_data;
	char buffer[BUFSIZ];

	/* 获取消息队列 */
	msgid = msgget((key_t)MSG_NAME, 0666 | IPC_CREAT);
	if (msgid == -1)
	{
		fprintf(stderr, "msgget failed with error: %d \n", errno);
		exit(EXIT_FAILURE);
	}
	while(running)
	{
		printf("Enter some text: ");
		fgets(buffer, BUFSIZ, stdin);
		some_data.my_msg_type = 1;
		strcpy(some_data.some_text, buffer);

		/* 发送消息 */
		if (msgsnd(msgid, (void *)&some_data, MAX_TEXT, 0) == -1)
		{
			fprintf(stderr, "msgrcv failed.\n");
			exit(EXIT_FAILURE);
		}
		if (strncmp(buffer, "end", 3) == 0)
		{
			running = 0;
		}
	}
	exit(EXIT_SUCCESS);
}

