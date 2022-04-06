/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_ft_putstr_fd_basic_test.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 14:51:25 by ctaleb            #+#    #+#             */
/*   Updated: 2022/04/03 15:37:56 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libft/libft.h"

int	ft_putstr_fd_basic_test(void)
{
	FILE	*fp;
	char	*line;
	size_t	size;

	ft_putstr_fd("42", 1);
	fp = fopen("tmp.txt", "r");
	if (fp == NULL)
		return (-1);
	line = NULL;
	getline(&line, &size, fp);
	fclose(fp);
	if (ft_strncmp(line, "42", 2) != 0)
	{
		if (line)
			free(line);
		return (-1);
	}
	if (line)
		free(line);
	return (0);
}
