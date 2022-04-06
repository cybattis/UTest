/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_timeout_launcher.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:59:38 by cybattis          #+#    #+#             */
/*   Updated: 2022/04/03 18:31:52 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "timeout_test.h"

int	timeout_launcher(int fd)
{
	t_unit_test	*test_list;

	test_list = NULL;
	load_test(&test_list, "Timeout test", &timeout_test);
	launch_tests(&test_list, "[TIMEOUT]", fd);
	return (0);
}
