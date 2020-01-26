/**************************************************************************** **
 * Copyright (C) 2010-2011 Cameo Communications, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : ex_6_8.c
 *     FIRST CREATION DATE    : 2020/01/24
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/01/24
 *     FILE DESCRIPTION       : 日志消息处理函数syslog()、openlog()、closelog()和setlogmask().
 *                            : 优先级从高到低：
 *                            ：LOG_EMERG, LOG_ALERT, LOG_CRIT, LOG_ERR, LOG_WARNING, LOG_NOTICE, LOG_INFO和LOG_DEBUG.
** ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <unistd.h>
#include <time.h>

/****************************************************************************
 *  Function Name : main
 *  Description   : The Main Function 写入日志文件/var/log/syslog中.
 *  Input(s)      : argc - The numbers of input value.
 *                : argv - The pointer to input specific parameters.
 *  Output(s)     : NULL
 *  Returns       : 0
 ****************************************************************************/
int main(int argc, const char *argv[])
{
	int mask;
	time_t rawtime;
	struct tm *timeinfo;
	char c[100];

	/* 默认优先级为LOG_INFO,故以下两条消息可以写入日志文件 */
	openlog("test:", LOG_PID, LOG_USER);
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	syslog(LOG_INFO, "Time current date/time is: %s \n", asctime(timeinfo));
	getcwd(c, sizeof(c));
	syslog(LOG_INFO, "you are in the direcory: %s \n", c);
	closelog();

	/* 将优先级设置为高于等于"LOG_NOTICE"，较低优先级的消息将不会写入日志文件 */
	mask = setlogmask(LOG_UPTO(LOG_NOTICE));    //返回值为当前的优先级;
	syslog(LOG_INFO, "LOG_INFO is inferior to LOG_NOTICE. \n");
	syslog(LOG_DEBUG, "LOG_DEBUG is inferior to LOG_NOTICE. \n");
	syslog(LOG_NOTICE, "you can see the notice. \n");

	setlogmask(mask);    //恢复之前mask保存的优先级;
	syslog(LOG_INFO, "restore the old log level. \n");
	syslog(LOG_DEBUG, "the debug information. \n");

    return 0;
}

