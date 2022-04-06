/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utest.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 22:15:58 by cybattis          #+#    #+#             */
/*   Updated: 2022/04/07 19:48:36 by cybattis         ###   ########.fr       */
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

/* macros to define test suite */
/* *************************** */

#define UTEST_BEGIN(name)
#define UTEST_END()
#define RUN_TEST(test)
#define IGNORE_TEST()

#define TIMEOUT 5
#define NO_LOG -1

/* macros to define assertion */
/* *************************** */

#define ASSERT(actual, expected)
#define ASSERT_MSG(actual, expected, message)

/* macros to define utils */
/* *************************** */

#define PRINT_STDERR(message)					dprintf(STDERR_FILENO, "./%s:%d: %s %s\n", __FILE__, __LINE__, ERROR, message)
#define PRINT_LOG(message)						dprintf(fd, "./%s:%d: %s %s\n", __FILE__, __LINE__, ERROR, message)

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

void		launch_tests(t_unit_test **testlist, char *f_name, int fd);
void		load_test(t_unit_test **test_list, char *test_name, int (*f)(void));

void		print_test(t_unit_test *testlist, t_utest_data *test_data, char *f_name);
void		print_test_status(int status);
void		print_result(int test_count, int test_passed);
void		log_test(t_unit_test *lst, t_utest_data *t_data, char *f_name, int fd);
void		log_test_status(int status, int fd);
void		log_result(t_utest_data test_data, int fd);
int			create_log_file(void);

#endif /* UTEST_H */
