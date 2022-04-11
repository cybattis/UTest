/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_ft_strlen_big_string_test.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:48:03 by ctaleb            #+#    #+#             */
/*   Updated: 2022/04/03 14:46:34 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libft/libft.h"
#include <string.h>

int	ft_strlen_timeout_test(void)
{
	size_t	val;
	size_t	val2;
	char	*str;

	str = "aaaaaaaaaaaaa bbbbbbbbbbbbb ccccccccccccc ddddddddddddddf"
		"nejwfn ejkwbnckl enwklcn eklwnckl nklewcn klenwkl nckewkl";
	val = ft_strlen(str);
	val2 = strlen(str);
	if (val == val2)
		return (0);
	return (-1);
}
