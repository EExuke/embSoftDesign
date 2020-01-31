/**************************************************************************** **
 * Copyright (C) 2010-2011 Cameo Communications, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : client1.c
 *     FIRST CREATION DATE    : 2020/01/31
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/01/31
 *     FILE DESCRIPTION       : 本地套接字编程实例.
** ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/un.h>

/****************************************************************************
 *  Function Name : main
 *  Description   : The Main Function is 本地套接字，客户端程序.
 *  Input(s)      : NULL
 *                :
 *  Output(s)     : NULL
 *  Returns       : 0
 ****************************************************************************/
int main()
{
	int sockfd;
	int len;
	struct sockaddr_un address;
	int result;
	char ch = 'A';
	/* 创建本地套接字 */
	sockfd = socket(AF_UNIX, SOCK_STREAM, 0);
	address.sun_family = AF_UNIX;
	/* 根据服务器情况，设定连接地址 */
	strcpy(address.sun_path, "server_socket");
	len = sizeof(address);
	result = connect(sockfd, (struct sockaddr *)&address, len);
	/* 出错则退出 */
	if (result == -1)
	{
		perror("oops: client1");
		exit(1);
	}
	write(sockfd, &ch, 1);
	read(sockfd, &ch, 1);
	printf("char from server = %c \n", ch);
	close(sockfd);
    exit(0);
}

