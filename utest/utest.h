/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utest.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 22:15:58 by cybattis          #+#    #+#             */
/*   Updated: 2022/04/10 22:23:24 by cybattis         ###   ########.fr       */
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

/* macros test suite */
/* *************************** */

#define UTEST_BEGIN(suite_name)					utest_begin(suite_name, STDERR_FILENO)
#define RUN_TEST(test_name, func)				run_test(test_name, func)
#define UTEST_END()								utest_end(STDERR_FILENO)

#define TIMEOUT 2

/* macros assertion */
/* *************************** */

#define ASSERT(actual, expected)
#define ASSERT_MSG(actual, expected, message)

/* macros utils */
/* *************************** */

#define PRINT_STDERR(message)					dprintf(STDERR_FILENO, "./%s:%d: %s %s\n", __FILE__, __LINE__, ERROR, message)
#define PRINT_LOG(message)						dprintf(fd, "./%s:%d: %s %s\n", __FILE__, __LINE__, ERROR, message)

#define OK			"\033[32m[OK]\n\033[00m"
#define KO			"\033[31m[KO]ERROR\n\033[00m"
#define IGNORE		"\033[34m[IGNORE]\n\033[00m"

#define P_SIGSEGV	"\033[33m[SIGSEGV]\n\033[0m"
#define P_SIGBUS	"\033[33m[SIGBUS]\n\033[0m"
#define P_SIGABRT	"\033[33m[SIGABRT]\n\033[0m"
#define P_SIGFPE	"\033[33m[SIGFPE]\n\033[0m"
#define P_SIGPIPE	"\033[33m[SIGPIPE]\n\033[0m"
#define P_SIGILL	"\033[33m[SIGILL]\n\033[0m"
#define P_TIMEOUT	"\033[1;30m[TIMEOUT]\n\033[0m"

#define TEST_FAIL	0
#define TEST_PASS	1
#define TEST_SIG	2
#define TEST_IGNORE	3

typedef struct s_utest_data
{
	int	test_count;
	int	test_passed;
	int	test_failed;
	int	test_ignored;
//	int	log_file;
}	t_utest_data;

t_utest_data	utest_data;

static void	utest_begin(char *suite_name, int fd)
{
	bzero(&utest_data, sizeof(t_utest_data));
	dprintf(fd, "\n%s\n", suite_name);
}

static void	utest_end(int fd)
{
	dprintf(fd, "%d/%d tests pass\n", utest_data.test_passed, utest_data.test_count);
}

static void	print_test_status(int status, char *test_name, int fd);

static int	run_test(char *test_name, int (*f)(void), ...)
{
	pid_t	pid;
	int		return_value;
	int		status;

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
		alarm(TIMEOUT);
		return_value = f();
		close(fd);
		exit(return_value);
	}
	utest_data.test_count++;
	wait(&status);
	if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status) == 0)
			utest_data.test_passed++;
		print_test_status(WEXITSTATUS(status), test_name, STDERR_FILENO);
	}
	else if (WIFSIGNALED(status))
		print_test_status(WTERMSIG(status), test_name, STDERR_FILENO);
	unlink("tmp");
	return (0);
}

static void	print_test_status(int status, char *test_name, int fd)
{
	dprintf(STDERR_FILENO, "%d - %s: ", utest_data.test_count, test_name);
	if (status == 0)
		dprintf(fd, "\033[32m[OK]\n\033[00m");
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

#endif /* UTEST_H */
