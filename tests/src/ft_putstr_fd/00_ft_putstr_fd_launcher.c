/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_ft_putstr_fd_launcher.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 14:46:53 by ctaleb            #+#    #+#             */
/*   Updated: 2022/04/03 15:53:20 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "ft_putstr_fd_test.h"

int	ft_putstr_fd_launcher(int fd)
{
	t_unit_test	*test_list;

	test_list = NULL;
	load_test(&test_list, "basic test", &ft_putstr_fd_basic_test);
	launch_tests(&test_list, "[FT_PUTSTR_FD]", fd);
	return (0);
}
