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
	/* hostent: h_name(主机名), h_aliases(主机别名列表), h_addrtype(地址类型), h_length(地址长度), h_addr_list(地址列表) */
	struct hostent * hostinfo;
	/* servent: s_name(服务名), s_aliases(别名列表), s_port(端口号), s_proto(协议类型TCP或UDP) */
	struct servent * servinfo;
	char buffer[128];
	if (argc == 1)
		host = "localhost";    //无参数，则连到本地主机名
	else
		host = argv[1];        //有参数，则连到参数代表的主机名
	/* 主机数据库函数，获取主机相关信息，主要获取地址 */
	hostinfo = gethostbyname(host);
	if (!hostinfo)
	{
		fprintf(stderr, "no host: %s \n", host);
		exit(1);
	}
	/* 服务及端口有关的服务信息函数，通过服务名获取信息，目的是获取daytime服务的端口号 */
	servinfo = getservbyname("daytime", "tcp");
	if (!servinfo)
	{
		fprintf(stderr, "no daytime service \n");
		exit(1);
	}
	/* 获取服务的端口号，转换格式后输出 */
	printf("daytime port is %d \n", ntohs(servinfo->s_port));
	/* 创建套接字 */
	sockfd = socket(AF_INET, SOCK_STREAM, 0);    //AF_INET 说明为网络套接字
	address.sin_family = AF_INET;    //服务器地址类型 为 网络套接字
	address.sin_port = servinfo->s_port;    //端口号
	address.sin_addr = *(struct in_addr *)*hostinfo->h_addr_list;    //主机地址
	len = sizeof(address);
	/* 连接到服务器 */
	result = connect(sockfd, (struct sockaddr *)&address, len);
	if (result == -1)
	{
		perror("oops: getdate");
		exit(1);
	}
	/* 读套接字sockfd */
	result = read(sockfd, buffer, sizeof(buffer));    //返回读取到的字节数
	buffer[result] = '\0';
	printf("read %d bytes: %s", result, buffer);
	close(sockfd);
	exit(0);
}

