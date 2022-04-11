/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulog_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 22:15:58 by cybattis          #+#    #+#             */
/*   Updated: 2022/04/11 17:54:07 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ulog.h"
#include <string.h>

int main(void)
{
	ULOG_INFO("Test Info log");
	ULOG_ERROR("Test Error log");
	ULOG_WARNING("Test Warning log");
	ULOG_UPDATE("Test Update log");
	ULOG_CRASH("Test Crash log");
	return (0);
}
