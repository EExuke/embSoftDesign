/**************************************************************************** **
 * Copyright (C) 2010-2011 Cameo Communications, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : udp_server.c
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
#define MESSAGE     "Hi, I recved your ACK!"
/****************************************************************************
 *  Function Name : main
 *  Description   : The Main Function is UDP网络套接字，服务器端程序，
 *                : 使用recvfrom()接收客户端数据，使用sendto()发送数据到客户端.
 *  Input(s)      : NULL
 *                :
 *  Output(s)     : NULL
 *  Returns       : 0
 ****************************************************************************/
int main()
{
	char read_buf[BUF_SIZE];
	char send_buf[BUF_SIZE] = MESSAGE;
	int rv, time_now;
	int server_sockfd;
	int server_len, client_len;
	struct sockaddr_in server_address;
	struct sockaddr_in client_address;

	/* 创建网络套接字 */
	server_sockfd = socket(AF_INET, SOCK_DGRAM, 0);    //SOCK_DGRAM 指定数据报型的套接字
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = htons(INADDR_ANY);    //htons使用网络字节序
	server_address.sin_port = htons(9734);

	/* 绑定服务器套接字 */
	server_len = sizeof(struct sockaddr);
	bind(server_sockfd, (struct sockaddr *)&server_address, server_len);

	/* 等待客户端连接请求 */
	while(1)
	{
		printf("server waiting\n");
		client_len = sizeof(struct sockaddr);
		/* 使用recvfrom()接收客户端数据 */
		rv = recvfrom(server_sockfd, read_buf, BUF_SIZE, 0, (struct sockaddr *)&client_address, &client_len);
		if (rv < 0)
		{
			printf("recvfrom error! \n");
			close(server_sockfd);
			return -1;
		}
		printf("IP: 0x%x, port: %d \n", ntohs(client_address.sin_addr.s_addr), ntohs(client_address.sin_port));
		printf("read_buf: %s \n", read_buf);

		/* 使用sendto()发送数据到客户端 */
		sendto(server_sockfd, send_buf, BUF_SIZE, 0, (struct sockaddr *)&client_address, client_len);
	}
	bzero(&client_address, client_len);
	bzero(read_buf, BUF_SIZE);
	bzero(send_buf, BUF_SIZE);
	return 0;
}

