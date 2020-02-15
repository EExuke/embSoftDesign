/**************************************************************************** **
 * Copyright (C) 2010-2011 Cameo Communications, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : server5.c
 *     FIRST CREATION DATE    : 2020/02/14
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/02/14
 *     FILE DESCRIPTION       : 网络套接字编程实例,多线程处理多客户问题。
** ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

void *thread_func(void *arg);
char ch;
int client_sockfd[5];
/****************************************************************************
 *  Function Name : main
 *  Description   : The Main Function is 网络套接字，服务器端程序，使用子线程处理多客户问题.
 *  Input(s)      : NULL
 *                :
 *  Output(s)     : NULL
 *  Returns       : 0
 ****************************************************************************/
int main()
{
	pthread_t tid[5];    //线程列表，预设5个客户处理线程
	int server_sockfd;
	int server_len, client_len, i, ret;
	struct sockaddr_in server_address;
	struct sockaddr_in client_address;
	unlink("server_socket");
	/* 创建网络套接字 */
	server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = htons(INADDR_ANY);    //htons使用网络字节序
	server_address.sin_port = htons(9734);
	server_len = sizeof(server_address);
	bind(server_sockfd, (struct sockaddr *)&server_address, server_len);
	listen(server_sockfd, 5);
	/* 等待客户端连接请求 */
	while(1)
	{
		printf("server waiting\n");
		client_len = sizeof(client_address);
		/* 建立通信套接字 */
		client_sockfd[i] = accept(server_sockfd, (struct sockaddr *)&client_address, &client_len);
		if (client_sockfd[i] == -1)
		{
			printf("accept client_sockfd error! \n");
			close(client_sockfd[i]);
		}
		/* 创建线程处理多客户端请求 */
		ret = pthread_create(&tid[i], NULL, thread_func, (void *)i);
		if (ret != 0)
		{
			printf("pthread create error! \n");
			close(client_sockfd[i]);
		}
		i++;
		i = (i % 5);    // 0 <= i <5
	}
	close(client_sockfd[i]);
	return 0;
}

/****************************************************************************
 *  Function Name : thread_func
 *  Description   : The Function is 处理多客户请求的线程函数.
 *  Input(s)      : i 线程序号， 也是客户序号
 *                :
 *  Output(s)     : NULL
 *  Returns       : NULL
 ****************************************************************************/
void *thread_func(void *arg)
{
	while (1)
	{
		read(client_sockfd[(int)arg], &ch, 1);
		sleep(5);
		ch++;
		write(client_sockfd[(int)arg], &ch, 1);
	}
	close(client_sockfd[(int)arg]);
	exit(0);
}

