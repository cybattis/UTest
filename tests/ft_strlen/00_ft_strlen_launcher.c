/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_ft_strlen_launcher.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:59:38 by cybattis          #+#    #+#             */
/*   Updated: 2022/04/03 15:53:20 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "ft_strlen_test.h"

int	ft_strlen_launcher(int fd)
{
	t_unit_test	*test_list;

	test_list = NULL;
	load_test(&test_list, "Basic test", &ft_strlen_basic_test);
	load_test(&test_list, "NULL test", &ft_strlen_null_test);
	load_test(&test_list, "Big string test", &ft_strlen_timeout_test);
	launch_tests(&test_list, "[FT_STRLEN]", fd);
	return (0);
}
