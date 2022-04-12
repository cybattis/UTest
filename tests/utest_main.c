/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utest_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 22:15:58 by cybattis          #+#    #+#             */
/*   Updated: 2022/04/13 00:34:00 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utest.h"
#include <string.h>

int utest_func_ok(void)
{
	return (0);
}

int utest_func_ko(void)
{
	return (1);
}

int	utest_sigsegv(void)
{
	strlen(NULL);
	return (1);
}

int utest_func_timeout(void)
{
	sleep(3);
	return (1);
}

int	utest_sigabort(void)
{
	abort();
}

int	utest_sigfpe(void)
{
	int	i;
	int	zero;

	zero = 0;
	i = 10;
	i = i / zero;
	return (0);
}

int	utest_sigpipe(void)
{
	int	fd[2];

	pipe(fd);
	dup2(fd[1], 1);
	close(fd[1]);
	close(fd[0]);
	write (1, "test", 4);
	exit(0);
}

int	utest_sigill(void)
{
	asm("ud2");
	return (0);
}

int main(void)
{
	char	*s1 = "coucou";
	char	*s2 = "nvjorwbvoow";
	char	*s3 = "coucou";
	char	*p1 = malloc(4);
	char	*p2 = NULL;

	UTEST_ASSERT_STR_EQUAL(s1, s2);
	UTEST_ASSERT_STR_NOT_EQUAL(s1, s3);
	UTEST_ASSERT_INT_EQUAL(10, 50);
	UTEST_ASSERT_INT_NOT_EQUAL(10, 10);
	UTEST_ASSERT_INT_GREATER(5, 10);
	UTEST_ASSERT_INT_GREATER_EQUAL(5, 10);
	UTEST_ASSERT_INT_LESSER(10, 5);
	UTEST_ASSERT_INT_LESSER_EQUAL(10, 5);
	UTEST_ASSERT_PTR_NULL(p1);
	UTEST_ASSERT_PTR_NOT_NULL(p2);
	UTEST_ASSERT_FALSE(0);
	UTEST_ASSERT_TRUE(1);

	UTEST_BEGIN("Suite #1 - Test the tests");
	RUN_TEST("Test ok", utest_func_ok);
	RUN_TEST("Test ko", utest_func_ko);
	RUN_TEST("Test ko", utest_func_ko, UT_IGNORE);
	RUN_TEST("Test sigsegv", utest_sigsegv);
	RUN_TEST("Test sigabort", utest_sigabort);
	RUN_TEST("Test sigfpe", utest_sigfpe);
	RUN_TEST("Test sigpipe", utest_sigpipe);
	RUN_TEST("Test sigill", utest_sigill);
	RUN_TEST("Test timeout", utest_func_timeout);
	UTEST_END();

	UTEST_BEGIN("Suite #2 - ReTest the tests");
	RUN_TEST("Test ok", utest_func_ok);
	RUN_TEST("Test ko", utest_func_ko);
	UTEST_END();

	return (0);
}
