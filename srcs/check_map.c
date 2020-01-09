/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 21:18:23 by thgermai          #+#    #+#             */
/*   Updated: 2020/01/09 22:29:58 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		check_last_line(char *line)
{
	int				i;

	i = -1;
	while (line[++i])
		if (line[i] != '1')
			return (0);
	return (1);
}

int		check_outline(char *line)
{
	static int		i = 0;
	int				j;

	j = -1;
	if (!i)
	{
		while (line[++j])
			if (line[j] != '1')
				return (0);
	}
	else
	{
		while (line[++j])
			if (ft_find_in("012NSEW", line[j]) == -1)
				return (0);
		if (line[0] != '1' || line[--j] != '1')
			return (0);
	}
	i++;
	return (1);
}

