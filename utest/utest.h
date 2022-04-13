/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utest.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 11:28:17 by cybattis          #+#    #+#             */
/*   Updated: 2022/04/13 17:42:09 by cybattis         ###   ########.fr       */
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

/* *************************** */
/*           Settings          */
/* *************************** */

#define UTEST_OUT		STDERR_FILENO
#define UT_TIMEOUT		2

/*     Utils    */
/* ************ */

#define UT_IGNORE		-1
#define UT_FAIL			0
#define UT_PASS			1
#define UT_SIG			2

#define _RED			"\x1b[31m"
#define _GREEN			"\x1b[32m"
#define _YELLOW			"\x1b[33m"
#define _BLUE			"\x1b[34m"
#define _MAGENTA		"\x1b[35m"
#define _CYAN			"\x1b[36m"
#define _GREY			"\x1b[30m"
#define _RESET			"\x1b[0m"

#define UT_ERROR		"[\033[31mERROR\033[0m]"
#define UT_WARNING		"[\033[33mWARNING\033[0m]"
#define UT_INFO			"[\033[32mINFO\033[0m]"
#define UT_DEBUG		"[\033[34mDEBUG\033[0m]"
#define UT_FATAL		"[\033[31mFATAL\033[0m]"

#define PRINTF_FORMAT(x) _Generic((x), \
    char: "%c", \
    signed char: "%hhd", \
    unsigned char: "%hhu", \
    signed short: "%hd", \
    unsigned short: "%hu", \
    signed int: "%d", \
    unsigned int: "%u", \
    long int: "%ld", \
    unsigned long int: "%lu", \
    long long int: "%lld", \
    unsigned long long int: "%llu", \
    float: "%f", \
    double: "%f", \
    long double: "%Lf", \
    char *: "%s", \
    void *: "%p")

#define PRINT_MSG(actual, msg, expected) \
		dprintf(STDERR_FILENO, PRINTF_FORMAT(actual), actual),		\
		dprintf(STDERR_FILENO, msg), 			\
        dprintf(STDERR_FILENO, PRINTF_FORMAT(expected), expected),	\
		dprintf(STDERR_FILENO, "\n")

#define VAR_NAME(var)	#var

/* Macros print */
/* ************ */

#define UTEST_PRINT_ASSERT_STR(level, actual, expected)			\
		dprintf(UTEST_OUT, "%s in "_YELLOW"%s\033[0m() /%s:%d: Expected: \"%s\" --> actual: \"%s\"\n", \
		level, __FUNCTION__ , __FILE__, __LINE__, expected, actual)

#define UTEST_PRINT_ASSERT_INT(level)	\
		dprintf(UTEST_OUT, "%s in "_YELLOW"%s\033[0m() /%s:%d: ", level, __FUNCTION__ , __FILE__, __LINE__)

#define UTEST_PRINT_ASSERT_BOOL(level, msg)						\
		dprintf(UTEST_OUT, "%s in "_YELLOW"%s\033[0m() /%s:%d: "msg"\n", \
		level, __FUNCTION__ , __FILE__, __LINE__)

#define UTEST_PRINT_ASSERT_PTR(level, var, expected) \
		dprintf(UTEST_OUT, "%s in "_YELLOW"%s\033[0m() /%s:%d: Pointer %s %s\n", \
		level, __FUNCTION__ , __FILE__, __LINE__, VAR_NAME(var), expected)


/* *************************** */
/*             Suite           */
/* *************************** */

#define UTEST_BEGIN(suite_name)							utest_begin(suite_name, UTEST_OUT)
#define RUN_TEST(test_name, func, ...)					run_test(test_name, func, ##__VA_ARGS__)
#define UTEST_END()										utest_end(UTEST_OUT)


/* *************************** */
/*            Assert           */
/* *************************** */

#define UTEST_ASSERT_STR_EQUAL(actual, expected)		\
		if (strcmp(actual, expected))					\
			UTEST_PRINT_ASSERT_STR(UT_ERROR, actual, expected)

#define UTEST_ASSERT_STR_NOT_EQUAL(actual, expected)	\
		if (!strcmp(actual, expected))					\
			UTEST_PRINT_ASSERT_STR(UT_ERROR, actual, expected)


#define UTEST_ASSERT_TRUE(value)		\
		if (value)						\
			UTEST_PRINT_ASSERT_BOOL(UT_ERROR, "Expected TRUE is FALSE")

#define UTEST_ASSERT_FALSE(value)		\
		if (!value)						\
			UTEST_PRINT_ASSERT_BOOL(UT_ERROR, "Expected FALSE is TRUE")


#define UTEST_ASSERT_INT_EQUAL(actual, expected)			\
		if (actual != expected)								\
			UTEST_PRINT_ASSERT_INT(UT_ERROR),				\
			PRINT_MSG(actual, " is not equal to ", expected)

#define UTEST_ASSERT_INT_NOT_EQUAL(actual, expected)		\
		if (actual == expected)								\
			UTEST_PRINT_ASSERT_INT(UT_ERROR),				\
			PRINT_MSG(actual, " is equal to ", expected)

#define UTEST_ASSERT_INT_GREATER(actual, expected)			\
		if (actual <= expected)								\
			UTEST_PRINT_ASSERT_INT(UT_ERROR),				\
			PRINT_MSG(actual, " is not greater than ", expected)

#define UTEST_ASSERT_INT_GREATER_EQUAL(actual, expected)	\
		if (actual < expected)								\
			UTEST_PRINT_ASSERT_INT(UT_ERROR),				\
			PRINT_MSG(actual, " is not greater or equal to ", expected)

#define UTEST_ASSERT_INT_LESSER(actual, expected)			\
		if (actual >= expected)								\
			UTEST_PRINT_ASSERT_INT(UT_ERROR),				\
			PRINT_MSG(actual, " is greater to ", expected)

#define UTEST_ASSERT_INT_LESSER_EQUAL(actual, expected)		\
		if (actual > expected)								\
			UTEST_PRINT_ASSERT_INT(UT_ERROR),				\
			PRINT_MSG(actual, " is greater or equal to ", expected)

#define UTEST_ASSERT_PTR_NULL(actual)		\
		if (actual)							\
			UTEST_PRINT_ASSERT_PTR(UT_ERROR, actual, "has to be null")

#define UTEST_ASSERT_PTR_NOT_NULL(actual)	\
		if (!actual)						\
			UTEST_PRINT_ASSERT_PTR(UT_ERROR, actual, "has to be not null")


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
	int 	flags;
	va_list args;
	pid_t	pid;
	int		return_value;
	int		status;

	utest_suite.count++;
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
