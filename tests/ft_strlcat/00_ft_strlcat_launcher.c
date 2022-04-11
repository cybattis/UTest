/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_ft_strlcat_launcher.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:59:38 by cybattis          #+#    #+#             */
/*   Updated: 2022/04/03 15:53:20 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "ft_strlcat_test.h"

int	ft_strlcat_launcher(int fd)
{
	t_unit_test	*test_list;

	test_list = NULL;
	load_test(&test_list, "NULL test", &ft_strlcat_null_test);
	load_test(&test_list, "NULL test 2", &ft_strlcat_null_test_2);
	load_test(&test_list, "NULL test 3", &ft_strlcat_null_test_3);
	load_test(&test_list, "Basic test", &ft_strlcat_basic_test);
	load_test(&test_list, "Long dst test", &ft_strlcat_long_dst_test);
	load_test(&test_list, "Long utest test", &ft_strlcat_long_src_test);
	load_test(&test_list, "Size < dst test", &ft_strlcat_size_test);
	load_test(&test_list, "Size < utest test", &ft_strlcat_size_test_2);
	launch_tests(&test_list, "[FT_STRLCAT]", fd);
	return (0);
}
