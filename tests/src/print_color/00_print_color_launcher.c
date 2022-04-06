/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_print_color_launcher.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:59:38 by cybattis          #+#    #+#             */
/*   Updated: 2022/04/03 18:31:17 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "print_color_test.h"

int	print_color_launcher(int fd)
{
	t_unit_test	*test_list;

	test_list = NULL;
	load_test(&test_list, "Print ok", &print_ok_test);
	load_test(&test_list, "Print ko", &print_ko_test);
	load_test(&test_list, "Print sig", &print_sig_test);
	launch_tests(&test_list, "[PRINT_COLOR]", fd);
	return (0);
}
