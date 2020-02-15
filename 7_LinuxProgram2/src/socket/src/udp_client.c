/**************************************************************************** **
 * Copyright (C) 2010-2011 Cameo Communications, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : udp_client.c
 *     FIRST CREATION DATE    : 2020/02/15
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/02/15
 *     FILE DESCRIPTION       : UDP网络套接字编程实例, 使用网络字节序统一大小端字序.
** ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUF_SIZE    100
#define MESSAGE     "Hello, UDP!"
/****************************************************************************
 *  Function Name : main
 *  Description   : The Main Function is UDP网络套接字，客户端程序.
 *                : 使用recvfrom()接收客户端数据，使用sendto()发送数据到客户端.
 *  Input(s)      : NULL
 *                :
 *  Output(s)     : NULL
 *  Returns       : 0
 ****************************************************************************/
int main()
{
	char send_buf[BUF_SIZE] = MESSAGE;
	char read_buf[BUF_SIZE];
	char flag;
	int sockfd;
	int server_len, rv, ret;
	struct sockaddr_in server_address;

	while (1)
	{
		/* 创建UDP网络套接字 */
		sockfd = socket(AF_INET, SOCK_DGRAM, 0);    //SOCK_DGRAM 指定为数据包类型的套接字
		server_address.sin_family = AF_INET;
		/* 根据服务器情况，设定连接地址 */
		server_address.sin_addr.s_addr = inet_addr("127.0.0.1");    //inet_addr的返回值已经是网络字序
		server_address.sin_port = htons(9734);    //htons使用网络字节序统一大小端字序
		server_len = sizeof(server_address);

		/* 使用sendto()发送数据到服务器 */
		sendto(sockfd, send_buf, BUF_SIZE, 0, (struct sockaddr *)&server_address, server_len);
		/* 使用recvfrom()接收服务器数据 */
		printf("before\n");
		rv = recvfrom(sockfd, read_buf, BUF_SIZE, 0, (struct sockaddr *)&server_address, &server_len);
		printf("after\n");
		if (rv < 0)
		{
			printf("recvfrom error! \n");
			close(sockfd);
			return -1;
		}
		printf("read_buf: %s \n", read_buf);
		printf("input 'q' to end! (other continue)\n");
		scanf("%s", &flag);
		ret = strcmp("q", &flag);
		if ( !ret )
		{
			printf("goodbye! \n");
			break;
		}
	}
	close(sockfd);
    return 0;;
}

