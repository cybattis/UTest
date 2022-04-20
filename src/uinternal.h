/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uinternal.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:33:41 by cybattis          #+#    #+#             */
/*   Updated: 2022/04/20 15:19:37 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UINTERNAL_H
#define UINTERNAL_H

/* *************************** */
/*            SHARED           */
/* *************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define _RED			"\x1b[31m"
#define _GREEN			"\x1b[32m"
#define _YELLOW			"\x1b[33m"
#define _BLUE			"\x1b[34m"
#define _MAGENTA		"\x1b[35m"
#define _CYAN			"\x1b[36m"
#define _GREY			"\x1b[30m"
#define _RESET			"\x1b[0m"

#define U_ERROR			"["_RED"ERROR"_RESET"]"
#define U_WARNING		"["_YELLOW"WARNING"_RESET"]"
#define U_INFO			"["_GREEN"INFO"_RESET"]"
#define U_DEBUG			"["_BLUE"DEBUG"_RESET"]"
#define U_FATAL			"["_RED"FATAL"_RESET"]"

#define VAR_NAME(var)	#var

#define PRINTF_FORMAT(x) _Generic((x), \
	char: "%c", \
	signed char: "%hhd", \
	unsigned char: "%hhu", \
	signed short: "%hd", \
	unsigned short: "%hu", \
	signed int: "%d", \
	unsigned int: "%u", \
	long int: "%ld", \
	unsigned long int: "%lu", \
	long long int: "%lld", \
	unsigned long long int: "%llu", \
	float: "%f", \
	double: "%f", \
	long double: "%Lf", \
	char *: "%s", \
	void *: "%p")

#define GET_ERRNO				strerror(errno)
#define PRINT_ERRNO(msg)		dprintf(STDERR_FILENO, msg"%s\n", GET_ERRNO)

/* *************************** */
/*          MACRO ULOG         */
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

static void get_time(int option);

#define ULOG_FATAL_INTERNAL(msg, ...)	get_time(TIME_FORMAT), \
		dprintf(ULOG_OUT, "%s " msg "\n", U_FATAL, ##__VA_ARGS__)

#define ULOG_ERROR_INTERNAL(msg, ...)	get_time(TIME_FORMAT), \
		dprintf(ULOG_OUT, "%s " msg "\n", U_ERROR, ##__VA_ARGS__)

#define ULOG_WARNING_INTERNAL(msg, ...)	get_time(TIME_FORMAT), \
		dprintf(ULOG_OUT, "%s " msg "\n", U_WARNING, ##__VA_ARGS__)

#define ULOG_INFO_INTERNAL(msg, ...)	get_time(TIME_FORMAT), \
		dprintf(ULOG_OUT, "%s " msg "\n", U_INFO, ##__VA_ARGS__)

#define ULOG_DEBUG_INTERNAL(msg, ...)	get_time(TIME_FORMAT), \
		dprintf(ULOG_OUT, "%s " msg "\n", U_DEBUG, ##__VA_ARGS__)

/* *************************** */
/*         MACRO UTEST         */
/* *************************** */



#endif //UINTERNAL_H
