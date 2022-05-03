/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulog.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 11:28:27 by cybattis          #+#    #+#             */
/*   Updated: 2022/05/03 13:46:45 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ULOG_H
#define ULOG_H

#include "uinternal.h"
#include <sys/time.h>
#include <time.h>

/* *************************** */
/*             CORE            */
/* *************************** */

/*
 * Define for LOG_LEVEL
 * */
#define LOG_OFF			0
#define LOG_ALL			1
#define NO_DEBUG		2
#define NO_INFO			3
#define NO_WARNING		4

/*
 * Define for TIME_FORMAT
 * */
#define NO_DATE			0
#define NO_TIME			1
#define DATE			2

#define ULOG_FATAL_INTERNAL(msg, ...)	ulog_get_time(TIME_FORMAT), \
		dprintf(ULOG_OUT, "%s " msg "\n", U_FATAL, ##__VA_ARGS__)

#define ULOG_ERROR_INTERNAL(msg, ...)	ulog_get_time(TIME_FORMAT), \
		dprintf(ULOG_OUT, "%s " msg "\n", U_ERROR, ##__VA_ARGS__)

#define ULOG_WARNING_INTERNAL(msg, ...)	ulog_get_time(TIME_FORMAT), \
		dprintf(ULOG_OUT, "%s " msg "\n", U_WARNING, ##__VA_ARGS__)

#define ULOG_INFO_INTERNAL(msg, ...)	ulog_get_time(TIME_FORMAT), \
		dprintf(ULOG_OUT, "%s " msg "\n", U_INFO, ##__VA_ARGS__)

#define ULOG_DEBUG_INTERNAL(msg, ...)	ulog_get_time(TIME_FORMAT), \
		dprintf(ULOG_OUT, "%s " msg "\n", U_DEBUG, ##__VA_ARGS__)


/* *************************** */
/*           Settings          */
/* *************************** */

/*
 * Set the date and time format of log message
 *
 *     NO_DATE - 15:48:59:53 [INFO] lorem ipsum test
 *     NO_TIME - [INFO] lorem ipsum test
 *     DATE    - 2022:04:15 15:49:52:03 [INFO] lorem ipsum test
 * */
#define TIME_FORMAT		NO_TIME

/*
 * Set which log level to print
 * All level below the set will not be print
 *
 *     LOG_OFF
 *     NO_WARNING - Do not print Warning level and below
 *     NO_DEBUG
 *     NO_INFO
 *     LOG_ALL
 * */
#define LOG_LEVEL		LOG_ALL

/*
 * Set the output stream
 * */
#define ULOG_OUT		STDERR_FILENO


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


/* *************************** */
/*     Function definition     */
/* *************************** */

static void ulog_get_time(int option)
{
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	struct timeval tv;
	long long	ms;

	if (option == NO_TIME)
		return ;
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
