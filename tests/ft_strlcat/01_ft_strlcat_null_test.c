/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_ft_strlcat_null_test.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:59:38 by cybattis          #+#    #+#             */
/*   Updated: 2022/04/03 14:31:04 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libft/libft.h"

int	ft_strlcat_null_test(void)
{
	char	*src;

	src = "coucou";
	ft_strlcat(NULL, src, 10);
	return (0);
}
