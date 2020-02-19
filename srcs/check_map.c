/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 21:18:23 by thgermai          #+#    #+#             */
/*   Updated: 2020/02/19 14:52:29 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			check_last_line(char *line)
{
	int				i;

	i = -1;
	while (line[++i])
	{
		if (line[i] != '1')
		{
			ft_printf(ERR_WRG_LST_LINE, i, line[i]);
			return (0);
		}
	}
	return (1);
}

int			check_first_line(char *line)
{
	int		j;

	j = -1;
	while (line[++j])
	{
		if (line[j] != '1')
		{
			ft_printf(ERR_WRG_OUTLINE, 0, j, line[j]);
			return (0);
		}
	}
	return (1);
}

void		complete_orientation(t_map *map)
{
	if (map->player.orientation == 'E')
	{
		map->player.dir_x = 0;
		map->player.dir_y = 1;
	}
	else if (map->player.orientation == 'W')
	{
		map->player.dir_x = 0;
		map->player.dir_y = -1;
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
	int				j;

	j = 0;
	while (line[j])
	{
		if (ft_find_in("NSEW", line[j]) != -1)
		{
			map->player.orientation = line[j];
			map->player.x = i + 0.5;
			map->player.y = j + 0.5;
			map->player.origin_x = i;
			map->player.origin_y = j;
			complete_orientation(map);
			if (map->player.spawn)
			{
				ft_printf(ERR_SPAWN_EXIST, i, j, line[j]);
				exit_prog(map);
			}
			map->player.spawn++;
		}
		j++;
	}
}

void		check_line(char *line, t_map *map)
{
	int				j;

	j = -1;
	if (!map->plan.current_line && !check_first_line(line))
		exit_prog(map);
	else
	{
		while (line[++j])
		{
			if (line[j] == '2')
				register_sprite(map, map->plan.current_line, j);
		}
		check_spawn(line, map, map->plan.current_line);
		if (line[0] != '1' || line[--j] != '1')
		{
			ft_printf(ERR_WRG_OUTLINE, map->plan.current_line, j, line[j]);
			exit_prog(map);
		}
	}
	map->plan.current_line++;
}
