/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit_test.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:59:38 by cybattis          #+#    #+#             */
/*   Updated: 2022/04/03 11:07:45 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_TEST_H
# define LIBUNIT_TEST_H

int	libunit_ok_test(void);
int	libunit_ko_test(void);
int	libunit_sigsegv_test(void);
int	libunit_sigbus_test(void);
int	libunit_sigabort_test(void);
int	libunit_sigfpe_test(void);
int	libunit_sigpipe_test(void);
int	libunit_sigill_test(void);
int	libunit_timeout_test(void);

#endif
