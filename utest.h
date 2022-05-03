/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utest.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 11:28:17 by cybattis          #+#    #+#             */
/*   Updated: 2022/05/03 15:02:54 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTEST_H
#define UTEST_H

#include "uinternal.h"
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>
#include <strings.h>
#include <stdarg.h>

/* *************************** */
/*           Settings          */
/* *************************** */

#define UTEST_OUT		STDERR_FILENO
#define UT_TIMEOUT		2
#define	UT_VERBOSE		0

/*     Utils    */
/* ************ */

/*  Set a test run for function who print to stdout */
#define UT_PRINT_TEST	-2
/*  Ignore a test */
#define UT_IGNORE		-1

#define UT_PASS			0
#define UT_FAIL			1
#define UT_SIG			2

/* Macros print */
/* ************ */

#define PRINT_NL				dprintf(STDERR_FILENO, "\n")

/* [LEVEL] in function() /path/to/file:line: */
#define PRINT_STAMP(level) \
		dprintf(UTEST_OUT, "%s in "_YELLOW"%s\033[0m() /%s:%d: ", level, __FUNCTION__ , __FILE__, __LINE__)

#define	PRINT_FORMAT(X)			dprintf(STDERR_FILENO, PRINTF_FORMAT(X), X)
#define	PRINT_FORMAT_NL(X) \
		dprintf(STDERR_FILENO, PRINTF_FORMAT(X), X), \
		PRINT_NL

#define PRINT_MSG_ASSERT_TYPE(actual, msg, expected)				\
		dprintf(STDERR_FILENO, PRINTF_FORMAT(actual), actual),		\
		dprintf(STDERR_FILENO, PRINTF_FORMAT(msg), msg), 			\
		dprintf(STDERR_FILENO, PRINTF_FORMAT(expected), expected),	\
		dprintf(STDERR_FILENO, "\n")

/* [LEVEL] in function() /path/to/file:line: "actual msg expected" */
#define UTEST_PRINT_ASSERT_ERROR_INT(level, actual, msg, expected)	\
		PRINT_STAMP(level),											\
		PRINT_MSG_ASSERT_TYPE(actual, msg, expected)

/* [LEVEL] in function() /path/to/file:line: */
#define UTEST_PRINT_ASSERT_ERROR(level, ...)	\
		PRINT_STAMP(level),											\
		dprintf(STDERR_FILENO, __VA_ARGS__),						\
		dprintf(STDERR_FILENO, "\n")


/* *************************** */
/*             Suite           */
/* *************************** */

/*
 * Start and initialize a test suite and give it a name
 */
#define UTEST_BEGIN(suite_name) \
		utest_begin(suite_name, UTEST_OUT)

/*
 * Usage: RUN_TEST(test_name, function, option)
 *
 * Option:
 *  - UT_PRINT_TEST : Setup a test for a function who print to stdout
 *  - UT_IGNORE : Ignore test
 *
 *  ex: RUN_TEST("Test ko", utest_func_ko, UT_IGNORE);
 *      RUN_TEST("Test ko", utest_func_ko, UT_PRINT_TEST);
 */
#define RUN_TEST(test_name, func, ...) \
		run_test(test_name, func, ##__VA_ARGS__)

/*
 * Print stats of the test suit
 */
#define UTEST_END() \
		utest_end(UTEST_OUT)


/* *************************** */
/*            Assert           */
/* *************************** */

/* Assert String */

#define UTEST_ASSERT_STR_EQUAL(actual, expected)		\
		if (strcmp(actual, expected))					\
			UTEST_PRINT_ASSERT_ERROR(U_ERROR, "Expected \"%s\" --> Actual \"%s\"", actual, expected), exit(1)

#define UTEST_ASSERT_STR_NOT_EQUAL(actual, expected)	\
		if (!strcmp(actual, expected))					\
			UTEST_PRINT_ASSERT_ERROR(U_ERROR, "Expected \"%s\" --> Actual \"%s\"", actual, expected), exit(1)

/* Assert Bool */

#define UTEST_ASSERT_TRUE(value)		\
		if (value)						\
			UTEST_PRINT_ASSERT_ERROR(U_ERROR, "Expected TRUE is FALSE"), exit(1)

#define UTEST_ASSERT_FALSE(value)		\
		if (!value)						\
			UTEST_PRINT_ASSERT_ERROR(U_ERROR, "Expected FALSE is TRUE"), exit(1)

/* Assert all type of integer */

#define UTEST_ASSERT_INT_EQUAL(actual, expected)			\
		if (actual != expected)								\
			UTEST_PRINT_ASSERT_ERROR_INT(U_ERROR, "", VAR_NAME(actual) " is not equal to ", expected), exit(1)

#define UTEST_ASSERT_INT_NOT_EQUAL(actual, expected)		\
		if (actual == expected)								\
			UTEST_PRINT_ASSERT_ERROR_INT(U_ERROR, "", VAR_NAME(actual) " cannot be equal to ", expected), exit(1)

#define UTEST_ASSERT_INT_GREATER(actual, expected)			\
		if (actual <= expected)								\
			UTEST_PRINT_ASSERT_ERROR_INT(U_ERROR, actual, " is not greater than ", expected), exit(1)

#define UTEST_ASSERT_INT_GREATER_EQUAL(actual, expected)	\
		if (actual < expected)								\
			UTEST_PRINT_ASSERT_ERROR_INT(U_ERROR, actual, " is not greater or equal to ", expected), exit(1)

#define UTEST_ASSERT_INT_LESSER(actual, expected)			\
		if (actual >= expected)								\
			UTEST_PRINT_ASSERT_ERROR_INT(U_ERROR, actual, " is greater to ", expected), exit(1)

#define UTEST_ASSERT_INT_LESSER_EQUAL(actual, expected)		\
		if (actual > expected)								\
			UTEST_PRINT_ASSERT_ERROR_INT(U_ERROR, actual, " is greater or equal to ", expected), exit(1)

/* Assert pointer */

#define UTEST_ASSERT_PTR_NULL(actual)		\
		if (actual)							\
			UTEST_PRINT_ASSERT_ERROR(U_ERROR, VAR_NAME(actual) " is not null"), exit(1)

#define UTEST_ASSERT_PTR_NOT_NULL(actual)	\
		if (!actual)						\
			UTEST_PRINT_ASSERT_ERROR(U_ERROR, VAR_NAME(actual) " is null"), exit(1)


/* *************************** */
/*      Global definition      */
/* *************************** */

typedef struct s_utest_data
{
	int	count;
	int	passed;
	int	failed;
	int	ignored;
}	t_utest_data;

t_utest_data	utest_suite;

/* *************************** */
/*     Function definition     */
/* *************************** */

static void	print_test_status(int status, char *test_name, int fd);

static void	utest_begin(char *suite_name, int fd)
{
	bzero(&utest_suite, sizeof(t_utest_data));
	dprintf(fd, "\n%s\n", suite_name);
}

static void	utest_end(int fd)
{
	dprintf(fd, "%d/%d tests pass\n", utest_suite.passed, utest_suite.count);
}

static int	run_test(char *test_name, int (*f)(void), ...)
{
	int 	fd;
	int 	flags[2];
	va_list args;
	pid_t	pid;
	int		return_value;
	int		status;

	utest_suite.count++;
	va_start(args, f);
	flags[0] = va_arg(args, int);
	flags[1] = va_arg(args, int);
	va_end(args);
	for (int i = 0; i < 2; ++i) {
		if (flags[i] == UT_IGNORE) {
			print_test_status(UT_IGNORE, test_name, STDERR_FILENO);
			return (-1);
		}
	}
	pid = fork();
	if (pid == -1)
		return (-1);
	else if (!pid)
	{
		fd = 0;
		for (int i = 0; i < 2; ++i) {
			if (flags[i] == UT_PRINT_TEST) {
				if ((fd = open("tmp", O_WRONLY | O_CREAT, 0644)) == -1)
					exit(-1);
				dup2(fd, 1);
				dup2(fd, 2);
				break;
			}
		}
		alarm(UT_TIMEOUT);
		return_value = f();
		close(fd);
		exit(return_value);
	}
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
		dprintf(fd, _GREEN "[OK]\n"_RESET);
	else if (status == 1)
		dprintf(fd, _RED "[KO]\n"_RESET);
	else if (status == SIGSEGV)
		dprintf(fd, _YELLOW "[SIGSEGV]\n"_RESET);
	else if (status == SIGBUS)
		dprintf(fd, _YELLOW "[SIGBUS]\n"_RESET);
	else if (status == SIGABRT)
		dprintf(fd, _YELLOW "[SIGABRT]\n"_RESET);
	else if (status == SIGFPE)
		dprintf(fd, _YELLOW "[SIGFPE]\n"_RESET);
	else if (status == SIGPIPE)
		dprintf(fd, _YELLOW "[SIGPIPE]\n"_RESET);
	else if (status == SIGILL)
		dprintf(fd, _YELLOW "[SIGILL]\n"_RESET);
	else if (status == SIGALRM)
		dprintf(fd, _GREY "[TIMEOUT]\n"_RESET);
	else
		dprintf(fd, "\033[34m[IGNORE]\n"_RESET);
}

#endif /* UTEST_H */
