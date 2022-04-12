/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulog.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 11:28:27 by cybattis          #+#    #+#             */
/*   Updated: 2022/04/13 00:05:24 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @ulog */

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

#define UL_ERROR	"[\033[31mERROR\033[0m]"
#define UL_WARNING	"[\033[33mWARNING\033[0m]"
#define UL_INFO		"[\033[32mINFO\033[0m]"
#define UL_DEBUG	"[\033[34mDEBUG\033[0m]"
#define UL_FATAL	"[\033[31mFATAL\033[0m]"


/** Set the output stream */
#define ULOG_OUT	STDERR_FILENO

#define NO_DEBUG

/* *************************** */
/*            MACROS           */
/* *************************** */

#ifdef	LOG_ALL
	#define ULOG_FATAL(msg)			dprintf(ULOG_OUT, "%s %s %s\n", "[TIME]", UL_FATAL, msg)
	#define ULOG_ERROR(msg)			dprintf(ULOG_OUT, "%s %s %s\n", "[TIME]", UL_ERROR, msg)
	#define ULOG_WARNING(msg)		dprintf(ULOG_OUT, "%s %s %s\n", "[TIME]", UL_WARNING, msg)
	#define ULOG_INFO(msg)			dprintf(ULOG_OUT, "%s %s %s\n", "[TIME]", UL_INFO, msg)
	#define ULOG_DEBUG(msg)			dprintf(ULOG_OUT, "%s %s %s\n", "[TIME]", UL_DEBUG, msg)
#elifdef NO_DEBUG
	#define ULOG_FATAL(msg)			dprintf(ULOG_OUT, "%s %s %s\n", "[TIME]", UL_FATAL, msg)
	#define ULOG_ERROR(msg)			dprintf(ULOG_OUT, "%s %s %s\n", "[TIME]", UL_ERROR, msg)
	#define ULOG_WARNING(msg)		dprintf(ULOG_OUT, "%s %s %s\n", "[TIME]", UL_WARNING, msg)
	#define ULOG_INFO(msg)			dprintf(ULOG_OUT, "%s %s %s\n", "[TIME]", UL_INFO, msg)
	#define ULOG_DEBUG(msg)			(void)0
#endif

#elifdef NO_INFO
	#define ULOG_FATAL(msg)			dprintf(ULOG_OUT, "%s %s %s\n", "[TIME]", UL_FATAL, msg)
	#define ULOG_ERROR(msg)			dprintf(ULOG_OUT, "%s %s %s\n", "[TIME]", UL_ERROR, msg)
	#define ULOG_WARNING(msg)		dprintf(ULOG_OUT, "%s %s %s\n", "[TIME]", UL_WARNING, msg)
#elifdef NO_WARNING
	#define ULOG_FATAL(msg)			dprintf(ULOG_OUT, "%s %s %s\n", "[TIME]", UL_FATAL, msg)
	#define ULOG_ERROR(msg)			dprintf(ULOG_OUT, "%s %s %s\n", "[TIME]", UL_ERROR, msg)

#endif

#endif /* ULOG_H */
