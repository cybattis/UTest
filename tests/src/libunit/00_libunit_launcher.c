/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_libunit_launcher.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:59:38 by cybattis          #+#    #+#             */
/*   Updated: 2022/04/03 19:17:45 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "libunit_test.h"

int	libunit_launcher(void)
{
	t_unit_test	*test_list;

	test_list = NULL;
	load_test(&test_list, "OK test", &libunit_ok_test);
	load_test(&test_list, "KO test", &libunit_ko_test);
	load_test(&test_list, "SISGSEV test", &libunit_sigsegv_test);
	load_test(&test_list, "SIGBUS test", &libunit_sigbus_test);
	load_test(&test_list, "SIGABORT test", &libunit_sigabort_test);
	load_test(&test_list, "SIGFPE test", &libunit_sigfpe_test);
	load_test(&test_list, "SISPIPE test", &libunit_sigpipe_test);
	load_test(&test_list, "SIGILL test", &libunit_sigill_test);
	load_test(&test_list, "TIMEOUT test", &libunit_timeout_test);
	launch_tests(&test_list, "[LIBUNIT]", NO_LOG);
	return (0);
}
