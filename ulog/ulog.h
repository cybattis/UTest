/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulog.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:49:17 by cybattis          #+#    #+#             */
/*   Updated: 2022/04/11 16:50:32 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ULOG_H
#define ULOG_H

#define ULOG_OUT	STDERR_FILENO

#define ULOG_INFO(msg)		dprintf(ULOG_OUT, "[INFO] %s\n", msg)

#endif /* ULOG_H */
