/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_ft_atoi_multi_minus_sign.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:59:38 by cybattis          #+#    #+#             */
/*   Updated: 2022/04/03 14:09:58 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libft/libft.h"
#include <stdlib.h>

int	ft_atoi_multi_minus_sign(void)
{
	int	val;
	int	val2;

	val = ft_atoi("---42");
	val2 = atoi("---42");
	if (val == val2)
		return (0);
	return (-1);
}
