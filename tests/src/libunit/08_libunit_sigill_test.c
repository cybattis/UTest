/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_libunit_sigill_test.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:59:38 by cybattis          #+#    #+#             */
/*   Updated: 2022/04/03 13:56:58 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	libunit_sigill_test(void)
{
	asm("ud2");
	return (0);
}
