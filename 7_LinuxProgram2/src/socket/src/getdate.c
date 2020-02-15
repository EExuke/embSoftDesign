/**************************************************************************** **
 * Copyright (C) 2010-2011 Cameo Communications, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : getdate.c
 *     FIRST CREATION DATE    : 2020/01/31
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/01/31
 *     FILE DESCRIPTION       : 连接到主机的标准服务,需要打开相应的服务;
 *                            : 这里的daytime服务默认是关闭的，所以需要打开：
 *                            ：sudo vim /etc/xinetd.d/daytime 将其中的disable的值改为no.
 *                            : 再重启xinetd服务：sudo /etc/init.d/xinetd restart
** ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>


/****************************************************************************
 *  Function Name : main
 *  Description   : The Main Function 使用套接字访问主机的标准服务.
 *  Input(s)      : argc - The numbers of input value.
 *                : argv - The pointer to input specific parameters.
 *  Output(s)     : NULL
 *  Returns       : 0
 ****************************************************************************/
int main(int argc, char *argv[])
{
	char * host;
	int sockfd;
	int len, result;
	struct sockaddr_in address;
	struct hostent * hostinfo;
	struct servent * servinfo;
	char buffer[128];
	if (argc == 1)
		host = "localhost";
	else
		host = argv[1];
	hostinfo = gethostbyname(host);
	if (!hostinfo)
	{
		fprintf(stderr, "no host: %s \n", host);
		exit(1);
	}
	servinfo = getservbyname("daytime", "tcp");
	if (!servinfo)
	{
		fprintf(stderr, "no daytime service \n");
		exit(1);
	}
	/* 获取服务的端口号 */
	printf("daytime port is %d \n", ntohs(servinfo->s_port));
	/* 创建套接字 */
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	address.sin_family = AF_INET;
	address.sin_port = servinfo->s_port;
	address.sin_addr = *(struct in_addr *)*hostinfo->h_addr_list;
	len = sizeof(address);
	result = connect(sockfd, (struct sockaddr *)&address, len);
	if (result == -1)
	{
		perror("oops: getdate");
		exit(1);
	}
	result = read(sockfd, buffer, sizeof(buffer));
	buffer[result] = '\0';
	printf("read %d bytes: %s", result, buffer);
	close(sockfd);
	exit(0);
}

