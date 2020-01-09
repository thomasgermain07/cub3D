/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 21:18:23 by thgermai          #+#    #+#             */
/*   Updated: 2020/01/09 23:52:21 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		check_last_line(char *line)
{
	int				i;

	i = -1;
	while (line[++i])
	{
		if (line[i] != '1')
		{
			ft_printf("Cub3d: Map error: Bad outline in map: (last line: column %d: char '%c')\n", i, line[i]);
			exit (0);
		}
	}
}

void		check_outline(char *line)
{
	static int		i = 0;
	int				j;

	j = -1;
	if (!i)
	{
		while (line[++j])
		{
			if (line[j] != '1')
			{
				ft_printf("Cub3d: Map error: Bad outline in map: (line %d: column %d: char '%c')\n", i, j, line[j]);
				exit (0);
			}
		}
	}
	else
	{
		while (line[++j])
		{
			if (ft_find_in("012NSEW", line[j]) == -1)
			{
				ft_printf("Cub3d: Map error: Wrong parameter in map: (line %d: column %d: char '%c')\n", i, j, line[j]);
				exit (0);
			}
		}
		if (line[0] != '1' || line[--j] != '1')
		{
			ft_printf("Cub3d: Map error: Bad outline in map: (line %d: column %d: char '%c')\n", i, j, line[j]);
			exit (0);
		}
	}
	i++;
}

