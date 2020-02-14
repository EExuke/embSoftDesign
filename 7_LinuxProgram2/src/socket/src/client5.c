/**************************************************************************** **
 * Copyright (C) 2010-2011 Cameo Communications, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : client5.c
 *     FIRST CREATION DATE    : 2020/02/14
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/02/14
 *     FILE DESCRIPTION       : 网络套接字编程实例, 服务器端使用多线程处理多客户问题.
** ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <arpa/inet.h>

/****************************************************************************
 *  Function Name : main
 *  Description   : The Main Function is 网络套接字，客户端程序.
 *  Input(s)      : NULL
 *                :
 *  Output(s)     : NULL
 *  Returns       : 0
 ****************************************************************************/
int main()
{
	int sockfd;
	int len;
	struct sockaddr_in address;
	int result;
	char ch = 'A';
	/* 生成网络套接字 */
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	address.sin_family = AF_INET;
	/* 根据服务器情况，设定连接地址 */
	address.sin_addr.s_addr = inet_addr("127.0.0.1");    //inet_addr的返回值已经是网络字序
	address.sin_port = htons(9734);    //htons使用网络字节序统一大小端字序
	len = sizeof(address);
	result = connect(sockfd, (struct sockaddr *)&address, len);
	/* 出错则退出 */
	if (result == -1)
	{
		perror("oops: client2");
		exit(1);
	}
	while(1)
	{
		write(sockfd, &ch, 1);
		read(sockfd, &ch, 1);
		printf("char from server = %c \n", ch);
	}
	close(sockfd);
	exit(0);
}

