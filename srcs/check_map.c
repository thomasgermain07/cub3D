/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 21:18:23 by thgermai          #+#    #+#             */
/*   Updated: 2020/01/21 12:45:04 by thgermai         ###   ########.fr       */
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

void		complete_orientation(t_map *map)
{
	if (map->player.orientation == 'W')
	{
		map->player.dir_x = 0;
		map->player.dir_y = -1;
	}
	else if (map->player.orientation == 'E')
	{
		map->player.dir_x = 0;
		map->player.dir_y = 1;
	}
	else if (map->player.orientation == 'N')
	{
		map->player.dir_x = -1;
		map->player.dir_y = 0;
	}
	else if (map->player.orientation == 'S')
	{
		map->player.dir_x = 1;
		map->player.dir_y = 0;
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
			complete_orientation(map);
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
	else
	{
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
	}
	i++;
}
