/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 09:20:10 by thgermai          #+#    #+#             */
/*   Updated: 2020/01/17 12:36:53 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		create_v_line(float x, t_map *map)
{
	int i;

	i = -1;
	while (++i < map->resolution.y_res)
		mlx_pixel_put(map->mlx_param.mlx, map->mlx_param.window, x, i, 16777215);
}

void		create_h_line(t_map *map)
{
	int				i;
	float			case_size;
	float			current;

	case_size = (float)map->resolution.y_res / map->plan.size_x;
	current = case_size;
	while (current < map->resolution.y_res)
	{
		i = -1;
		while (++i < map->resolution.x_res)
			mlx_pixel_put(map->mlx_param.mlx, map->mlx_param.window, i, current, 16777215);
		current += case_size;
	}
}

void		create_mapping(t_map *map)
{
	float			case_size;
	float			current;

	case_size = (float)map->resolution.x_res / map->plan.size_y;
	current = case_size;
	while (current < map->resolution.x_res)
	{
		printf("%f\n", current);
		create_v_line(current, map);
		current += case_size;
	}
	create_h_line(map);
}
