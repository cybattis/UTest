/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_ft_strlcat_size_test.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:59:38 by cybattis          #+#    #+#             */
/*   Updated: 2022/04/03 15:11:43 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libft/libft.h"
#include <string.h>

static int	test_func(char *dst, char *src, size_t n);

int	ft_strlcat_size_test(void)
{
	char	dst[15];

	ft_strlcpy(dst, "coucou", 7);
	if (!test_func(dst, "helloolomamamamam", 4))
		return (0);
	return (-1);
}

static int	test_func(char *dst, char *src, size_t n)
{
	size_t	val;

	val = ft_strlcat(dst, src, n);
	if (val == 21 && !ft_strncmp(dst, "coucou", ft_strlen(dst)))
		return (0);
	return (-1);
}
