/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulog.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 11:28:27 by cybattis          #+#    #+#             */
/*   Updated: 2022/04/14 19:00:36 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ULOG_H
#define ULOG_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

/* *************************** */
/*           Settings          */
/* *************************** */

#define LOG_OFF			0
#define LOG_ALL			1
#define NO_DEBUG		2
#define NO_INFO			3
#define NO_WARNING		4

#define NO_DATE			0
#define DATE			1

#define TIME_FORMAT		NO_DATE

/* Set which log level to print */
#define LOG_LEVEL		LOG_ALL

/* Set the output stream */
#define ULOG_OUT		STDERR_FILENO

#define _RED			"\x1b[31m"
#define _GREEN			"\x1b[32m"
#define _YELLOW			"\x1b[33m"
#define _BLUE			"\x1b[34m"
#define _MAGENTA		"\x1b[35m"
#define _CYAN			"\x1b[36m"
#define _GREY			"\x1b[30m"
#define _RESET			"\x1b[0m"

#define UL_ERROR		"["_RED"ERROR"_RESET"]"
#define UL_WARNING		"["_YELLOW"WARNING"_RESET"]"
#define UL_INFO			"["_GREEN"INFO"_RESET"]"
#define UL_DEBUG		"["_BLUE"DEBUG"_RESET"]"
#define UL_FATAL		"["_RED"FATAL"_RESET"]"

static void get_time(int option);

#define ULOG_FATAL_INTERNAL(msg, ...)	get_time(TIME_FORMAT), dprintf(ULOG_OUT, "%s " msg "\n", UL_FATAL, ##__VA_ARGS__)
#define ULOG_ERROR_INTERNAL(msg, ...)	get_time(TIME_FORMAT), dprintf(ULOG_OUT, "%s " msg "\n", UL_ERROR, ##__VA_ARGS__)
#define ULOG_WARNING_INTERNAL(msg, ...)	get_time(TIME_FORMAT), dprintf(ULOG_OUT, "%s " msg "\n", UL_WARNING, ##__VA_ARGS__)
#define ULOG_INFO_INTERNAL(msg, ...)	get_time(TIME_FORMAT), dprintf(ULOG_OUT, "%s " msg "\n", UL_INFO, ##__VA_ARGS__)
#define ULOG_DEBUG_INTERNAL(msg, ...)	get_time(TIME_FORMAT), dprintf(ULOG_OUT, "%s " msg "\n", UL_DEBUG, ##__VA_ARGS__)

/* *************************** */
/*            MACROS           */
/* *************************** */

#if	LOG_LEVEL == LOG_ALL
	#define ULOG_FATAL(msg, ...)		ULOG_FATAL_INTERNAL(msg, ##__VA_ARGS__)
	#define ULOG_ERROR(msg, ...)		ULOG_ERROR_INTERNAL(msg, ##__VA_ARGS__)
	#define ULOG_WARNING(msg, ...)		ULOG_WARNING_INTERNAL(msg, ##__VA_ARGS__)
	#define ULOG_INFO(msg, ...)			ULOG_INFO_INTERNAL(msg, ##__VA_ARGS__)
	#define ULOG_DEBUG(msg, ...)		ULOG_DEBUG_INTERNAL(msg, ##__VA_ARGS__)
#elif LOG_LEVEL == NO_DEBUG
	#define ULOG_FATAL(msg, ...)		ULOG_FATAL_INTERNAL(msg, ##__VA_ARGS__)
	#define ULOG_ERROR(msg, ...)		ULOG_ERROR_INTERNAL(msg, ##__VA_ARGS__)
	#define ULOG_WARNING(msg, ...)		ULOG_WARNING_INTERNAL(msg, ##__VA_ARGS__)
	#define ULOG_INFO(msg, ...)			ULOG_INFO_INTERNAL(msg, ##__VA_ARGS__)
	#define ULOG_DEBUG(msg, ...)		(void)0
#elif LOG_LEVEL == NO_INFO
	#define ULOG_FATAL(msg, ...)		ULOG_FATAL_INTERNAL(msg, ##__VA_ARGS__)
	#define ULOG_ERROR(msg, ...)		ULOG_ERROR_INTERNAL(msg, ##__VA_ARGS__)
	#define ULOG_WARNING(msg, ...)		ULOG_WARNING_INTERNAL(msg, ##__VA_ARGS__)
	#define ULOG_INFO(msg, ...)			(void)0
	#define ULOG_DEBUG(msg, ...)		(void)0
#elif LOG_LEVEL == NO_WARNING
	#define ULOG_FATAL(msg, ...)		ULOG_FATAL_INTERNAL(msg, ##__VA_ARGS__)
	#define ULOG_ERROR(msg, ...)		ULOG_ERROR_INTERNAL(msg, ##__VA_ARGS__)
	#define ULOG_WARNING(msg, ...)		(void)0
	#define ULOG_INFO(msg, ...)			(void)0
	#define ULOG_DEBUG(msg, ...)		(void)0
#elif LOG_LEVEL == LOG_OFF
	#define ULOG_FATAL(msg, ...)		(void)0
	#define ULOG_ERROR(msg, ...)		(void)0
	#define ULOG_WARNING(msg, ...)		(void)0
	#define ULOG_INFO(msg, ...)			(void)0
	#define ULOG_DEBUG(msg, ...)		(void)0
#endif

static void get_time(int option)
{
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	struct timeval tv;
	long long	ms;

	gettimeofday(&tv,NULL);
	ms = tv.tv_usec / 10000;

	if (option == DATE)
		dprintf(ULOG_OUT, "%02d:%02d:%02d ", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
	dprintf(ULOG_OUT, "%02d:%02d:%02d:%02lld ",
			tm.tm_hour,
			tm.tm_min,
			tm.tm_sec,
			ms);
}

#endif /* ULOG_H */
