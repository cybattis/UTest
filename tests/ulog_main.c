/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulog_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 22:15:58 by cybattis          #+#    #+#             */
/*   Updated: 2022/04/14 18:52:48 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ulog.h"
#include <string.h>

int main(void)
{
	int n1 = 10;

	ULOG_FATAL("Test Fatal log");
	ULOG_FATAL("Test Fatal log %d", n1);
	ULOG_ERROR("Test Error log");
	ULOG_ERROR("Test Error log %d", n1);
	ULOG_WARNING("Test Warning log");
	for (int i = 0; i < 10; ++i)
	{
		usleep(10000);
		ULOG_INFO("Test Info log");
	}
	ULOG_DEBUG("Test Debug log");
	return (0);
}
