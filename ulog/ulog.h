/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulog.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:49:17 by cybattis          #+#    #+#             */
/*   Updated: 2022/04/11 19:35:17 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ULOG_H
#define ULOG_H

#include <unistd.h>
#include <stdio.h>

#define UL_INFO		"[\033[32mINFO\033[0m]"
#define UL_ERROR	"[\033[31mERROR\033[0m]"
#define UL_WARNING	"[\033[33mWARNING\033[0m]"
#define UL_UPDATE	"[\033[34mUPDATE\033[0m]"
#define UL_CRASH	"[\033[31mCRASH\033[0m]"

#define ULOG_OUT	STDERR_FILENO

#define ULOG_INFO(msg)			dprintf(ULOG_OUT, UL_INFO" %s\n", msg)
#define ULOG_ERROR(msg)			dprintf(ULOG_OUT, UL_ERROR" %s\n", msg)
#define ULOG_WARNING(msg)		dprintf(ULOG_OUT, UL_WARNING" %s\n", msg)
#define ULOG_UPDATE(msg)		dprintf(ULOG_OUT, UL_UPDATE" %s\n", msg)
#define ULOG_CRASH(msg)			dprintf(ULOG_OUT, UL_CRASH" %s\n", msg)

#endif /* ULOG_H */
