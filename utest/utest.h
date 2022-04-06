/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utest.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 22:15:58 by cybattis          #+#    #+#             */
/*   Updated: 2022/04/06 22:32:03 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTEST_H
#define UTEST_H

#include <stdio.h>
#include <stdlib.h>

#ifndef EXCLUDE_LIMITS_H
	#include <limits.h>
#endif

/**********************************\
 *   macros to define test suite
 **********************************/

#define UTEST_BEGIN(name)	 					utest_begin(utest, name);
#define UTEST_END()	 							utest_end(utest)
#define RUN_TEST(test, ...)						utest.status = TEST_FAIL; utest.number++; __VA_ARGS__; if (utest.status != TEST_IGNORE) test
#define IGNORE_TEST()							utest.status = TEST_IGNORE; utest.ignored++

#define ASSERT_S(condition, name)				CHECK(condition, utest.failed++) UTEST_PRINT(actual, expected, name)
#define INT_S(actual, expected, name)			CHECK(actual == expected, utest.failed++) UTEST_PRINT(actual, expected, name)
#define STR_S(actual, expected, name)			CHECK(!utest_strcmp(actual, expected), utest.failed++) UTEST_PRINT(actual, expected, name)
#define STR_LEN_S(actual, expected, name)		CHECK(!utest_strcmp_len(actual, expected), utest.failed++) UTEST_PRINT(actual, expected, name)
#define ASSERT_MSG(condition, message, ...)		if(condition){} else{ PRINT_ERROR(message); __VA_ARGS__ }
#define ASSERT(condition, ...)					ASSERT_MSG(condition, #condition, __VA_ARGS__)
#define ASSERT_PTR_NULL(ptr, message)	 		if(ptr){ PRINT_ERROR(message) CLEANUP_PTR(ptr); }
#define INT_U(actual, expected)					CHECK(actual == expected) UTEST_PRINT(actual, expected, NULL)
#define STR_U(actual, expected)					CHECK(!utest_strcmp(actual, expected) UTEST_PRINT(actual, expected, NULL)
#define STR_LEN_U(actual, expected)				CHECK(!utest_strcmp_len(actual, expected) UTEST_PRINT(actual, expected, NULL)

#define PRINT_ERROR(message)					fprintf(stderr, "./%s:%d: %s %s\n", __FILE__, __LINE__, ERROR, message);
#define PRINT_ERROR(message)					fprintf(log, "./%s:%d: %s %s\n", __FILE__, __LINE__, ERROR, message);

#define CLEANUP_PTR(ptr)						do{ ptr = NULL; free(ptr); abort(); }while(0);
#define UTEST_PRINT(actual, expected, name)		utest_print_s(__FILE__, __LINE__, actual, expected, name)
#define CHECK(condition, update_suite)			if(condition) utest.status = TEST_PASS; else{ utest.status = TEST_FAIL; update_suite; }

/* struct holding data from test suite (name, number, failed, ignored) */
typedef struct s_unit_test
{
	char	*test_name;
	int		(*f)(void);
	void	*next;
}	t_unit_test;

typedef struct s_utest_data
{
	int		test_count;
	int		test_passed;
	int		test_ignored;
	int		test_warning;
	int		test_failed_signal;
	pid_t	pid;
}	t_utest_data;

#ifdef NO_COLOR
	#define OK		"OK"
	#define PASS	"PASS"
	#define IGNORE	"IGNORE"
	#define FAIL	"FAIL"
	#define ERROR	"ERROR"
#else
	#define DEF		""
	#define OK		"\033[32mOK\033[00m"
	#define PASS	"\033[32mPASS\033[00m"
	#define IGNORE	"\033[34mIGNORE\033[00m"
	#define FAIL	"\033[31mFAIL\033[00m"
	#define ERROR	"\033[31mERROR\033[00m"
#endif

#define TEST_FAIL	0
#define TEST_PASS	1
#define TEST_SIG	2
#define TEST_IGNORE	3

#endif /* UTEST_H */
