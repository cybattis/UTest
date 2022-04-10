/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 22:15:58 by cybattis          #+#    #+#             */
/*   Updated: 2022/04/10 22:10:19 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utest/utest.h"

int test_func_ok(void)
{
	return (0);
}

int test_func_ko(void)
{
	return (1);
}

int test_func_timeout(void)
{
	sleep(3);
	return (1);
}

int main(void)
{
	UTEST_BEGIN("Suite #1 - Test the tests");
	RUN_TEST("Test ok", test_func_ok);
	RUN_TEST("Test ko", test_func_ko);
	RUN_TEST("Test timeout", test_func_timeout);
	UTEST_END();

	UTEST_BEGIN("Suite #2 - ReTest the tests");
	RUN_TEST("Test ok", test_func_ok);
	RUN_TEST("Test ko", test_func_ko);
	UTEST_END();

	return (0);
}
