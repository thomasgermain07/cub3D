/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 21:18:23 by thgermai          #+#    #+#             */
/*   Updated: 2020/01/10 14:58:09 by thgermai         ###   ########.fr       */
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
			ft_printf(ERR_WRG_LST_LINE, i, line[i]);
			exit(0);
		}
	}
}

void		check_first_line(char *line)
{
	int		j;

	j = -1;
	while (line[++j])
	{
		if (line[j] != '1')
		{
			ft_printf(ERR_WRG_OUTLINE, 0, j, line[j]);
			exit(0);
		}
	}
}

void		check_spawn(char *line, t_map *map, int i)
{
	static int		spawn = 0;
	int				j;

	j = 0;
	while (line[j])
	{
		if (ft_find_in("NSEW", line[j]) != -1)
		{
			map->player.orientation = line[j];
			map->player.x = i;
			map->player.y = j;
			if (spawn)
			{
				ft_printf(ERR_SPAWN_EXIST, i, j, line[j]);
				exit(0);
			}
			spawn++;
		}
		j++;
	}
}

void		check_line(char *line, t_map *map)
{
	static int		i = 0;
	int				j;

	j = -1;
	if (!i)
		check_first_line(line);
	while (line[++j])
	{
		if (ft_find_in("012NSEW", line[j]) == -1)
		{
			ft_printf(ERR_WRG_PAR, i, j, line[j]);
			exit(0);
		}
	}
	check_spawn(line, map, i);
	if (line[0] != '1' || line[--j] != '1')
	{
		ft_printf(ERR_WRG_OUTLINE, i, j, line[j]);
		exit(0);
	}
	i++;
}
