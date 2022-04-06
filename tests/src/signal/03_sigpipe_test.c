/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_libunit_sigpipe_test.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:59:38 by cybattis          #+#    #+#             */
/*   Updated: 2022/04/03 13:55:58 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	sigpipe_test(void)
{
	int	fd[2];

	pipe(fd);
	dup2(fd[1], 1);
	close(fd[1]);
	close(fd[0]);
	write (1, "test", 4);
	exit(0);
}
