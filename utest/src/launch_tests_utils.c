/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_tests_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 15:14:21 by ctaleb            #+#    #+#             */
/*   Updated: 2022/04/03 16:10:33 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libunit.h"
#include <stdio.h>
#include <fcntl.h>

void	log_result(t_test_data test_data, int fd)
{
	dprintf(fd, "\n%d/%d tests checked\t%d tests failed by signal\n\n",
		test_data.test_passed,
		test_data.test_passed,
		test_data.test_passed);
}

void	log_test(t_unit_test *lst, t_test_data *t_data, char *f_name, int fd)
{
	dprintf(fd, "\n%s %d: %s: t", f_name, t_data->test_count, lst->test_name);
}

void	log_test_status(int status, int fd)
{
	if (status == 0)
		dprintf(fd, "\033[32m[OK]\n\033[0m");
	else if (status == SIGSEGV)
		dprintf(fd, "\033[33m[SIGSEGV]\n\033[0m");
	else if (status == SIGBUS)
		dprintf(fd, "\033[33m[SIGBUS]\n\033[0m");
	else if (status == SIGABRT)
		dprintf(fd, "\033[33m[SIGABRT]\n\033[0m");
	else if (status == SIGFPE)
		dprintf(fd, "\033[33m[SIGFPE]\n\033[0m");
	else if (status == SIGPIPE)
		dprintf(fd, "\033[33m[SIGPIPE]\n\033[0m");
	else if (status == SIGILL)
		dprintf(fd, "\033[33m[SIGILL]\n\033[0m");
	else if (status == SIGALRM)
		dprintf(fd, "\033[1;30m[TIMEOUT]\n\033[0m");
	else
		dprintf(fd, "\033[31m[KO]\n\033[0m");
}

void	print_result(int test_count, int test_passed)
{
	log_result(test_count, test_passed, 1);
}

void	print_test(t_unit_test *lst, t_test_data *t_data, char *f_name)
{
	log_test(lst, t_data, f_name, 1);
}

void	print_test_status(int status)
{
	log_test_status(status, 1);
}

int	create_log_file(void)
{
	int	fd;

	fd = open("log.txt", O_CREAT | O_RDWR | O_TRUNC, 0666);
	if (!fd)
		return (-1);
	return (fd);
}
