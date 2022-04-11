/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utest.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 22:15:58 by cybattis          #+#    #+#             */
/*   Updated: 2022/04/11 14:44:41 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTEST_H
#define UTEST_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <strings.h>
#include <stdarg.h>

/* Settings */
/* *************************** */

#define UTEST_OUT	STDERR_FILENO
#define UT_TIMEOUT	2

/* Macros test suite */
/* *************************** */

#define UTEST_BEGIN(suite_name)			utest_begin(suite_name, UTEST_OUT)
#define RUN_TEST(test_name, func, ...)	run_test(test_name, func, ##__VA_ARGS__)
#define UTEST_END()						utest_end(UTEST_OUT)

/* Macros utils */
/* *************************** */

#define UT_IGNORE	-1
#define UT_FAIL		0
#define UT_PASS		1
#define UT_SIG		2

/* Function definition */
/* *************************** */

typedef struct s_utest_data
{
	int	count;
	int	passed;
	int	failed;
	int	ignored;
}	t_utest_data;

t_utest_data	utest_suite;

static void	utest_begin(char *suite_name, int fd)
{
	bzero(&utest_suite, sizeof(t_utest_data));
	dprintf(fd, "\n%s\n", suite_name);
}

static void	utest_end(int fd)
{
	dprintf(fd, "%d/%d tests pass\n", utest_suite.passed, utest_suite.count);
}

static void	print_test_status(int status, char *test_name, int fd);

static int	run_test(char *test_name, int (*f)(void), ...)
{
	int 	flags;
	va_list args;
	pid_t	pid;
	int		return_value;
	int		status;

	va_start(args, f);
	flags = va_arg(args, int);
	va_end(args);
	if (flags == UT_IGNORE)
	{
		print_test_status(UT_IGNORE, test_name, STDERR_FILENO);
		return (-1);
	}
	pid = fork();
	if (pid == -1)
		return (-1);
	else if (!pid)
	{
		int	fd = open("tmp", O_WRONLY | O_CREAT, 0644);
		if (fd == -1)
			exit(-1);
		dup2(fd, 1);
		dup2(fd, 2);
		alarm(UT_TIMEOUT);
		return_value = f();
		close(fd);
		exit(return_value);
	}
	utest_suite.count++;
	wait(&status);
	if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status) == 0)
			utest_suite.passed++;
		print_test_status(WEXITSTATUS(status), test_name, STDERR_FILENO);
	}
	else if (WIFSIGNALED(status))
		print_test_status(WTERMSIG(status), test_name, STDERR_FILENO);
	unlink("tmp");
	return (0);
}

static void	print_test_status(int status, char *test_name, int fd)
{
	dprintf(STDERR_FILENO, "%d - %s: ", utest_suite.count, test_name);
	if (status == 0)
		dprintf(fd, "\033[32m[OK]\n\033[0m");
	else if (status == 1)
		dprintf(fd, "\033[31m[KO]\n\033[0m");
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
		dprintf(fd, "\033[34m[IGNORE]\n\033[0m");
}

#endif /* UTEST_H */
