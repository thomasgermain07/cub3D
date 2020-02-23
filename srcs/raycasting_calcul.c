/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_calcul.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:12:44 by thgermai          #+#    #+#             */
/*   Updated: 2020/02/23 13:36:38 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_up_camera(t_map *map)
{
	if (map->player.dir_x == -1.0)
		map->camera.plan_y = 1.0;
	else if (map->player.dir_y == -1.0)
		map->camera.plan_x = -1.0;
	else if (map->player.dir_x == 1.0)
		map->camera.plan_y = -1.0;
	else if (map->player.dir_y == 1.0)
		map->camera.plan_x = 1.0;
}

void	initiate_algo_value(t_map *map, int x)
{
	map->camera.camera_x = (2.0 * (float)x /
		(float)map->resolution.x_res) - 1.0;
	map->camera.ray_pos_x = map->player.x;
	map->camera.ray_pos_y = map->player.y;
	map->camera.ray_dir_x = map->player.dir_x + map->camera.plan_x *
		map->camera.camera_x;
	map->camera.ray_dir_y = map->player.dir_y + map->camera.plan_y *
		map->camera.camera_x;
	map->camera.map_x = (int)map->camera.ray_pos_x;
	map->camera.map_y = (int)map->camera.ray_pos_y;
	map->camera.delta_dist_x = sqrt(1.0 + (map->camera.ray_dir_y *
		map->camera.ray_dir_y) / (map->camera.ray_dir_x *
		map->camera.ray_dir_x));
	map->camera.delta_dist_y = sqrt(1.0 + (map->camera.ray_dir_x *
		map->camera.ray_dir_x) / (map->camera.ray_dir_y *
		map->camera.ray_dir_y));
	map->camera.hit = 0;
	map->camera.side = 0;
}

void	get_ray_dir(t_map *map)
{
	if (map->camera.ray_dir_x < 0)
	{
		map->camera.step_x = -1.0;
		map->camera.side_dist_x = (map->camera.ray_pos_x -
			map->camera.map_x) * map->camera.delta_dist_x;
	}
	else
	{
		map->camera.step_x = 1.0;
		map->camera.side_dist_x = (map->camera.map_x + 1 -
			map->camera.ray_pos_x) * map->camera.delta_dist_x;
	}
	if (map->camera.ray_dir_y < 0)
	{
		map->camera.step_y = -1.0;
		map->camera.side_dist_y = (map->camera.ray_pos_y -
			map->camera.map_y) * map->camera.delta_dist_y;
	}
	else
	{
		map->camera.step_y = 1.0;
		map->camera.side_dist_y = (map->camera.map_y + 1 -
			map->camera.ray_pos_y) * map->camera.delta_dist_y;
	}
}

void	check_for_hit(t_map *map)
{
	while (!map->camera.hit)
	{
		if (map->camera.side_dist_x < map->camera.side_dist_y)
		{
			map->camera.side_dist_x += map->camera.delta_dist_x;
			map->camera.map_x += map->camera.step_x;
			map->camera.side = 0;
		}
		else
		{
			map->camera.side_dist_y += map->camera.delta_dist_y;
			map->camera.map_y += map->camera.step_y;
			map->camera.side = 1;
		}
		if (map->plan.plan[map->camera.map_x][map->camera.map_y] == '1')
			map->camera.hit = 1;
		else if (map->plan.plan[map->camera.map_x][map->camera.map_y] == '3')
			map->camera.hit = 2;
		else if (map->plan.plan[map->camera.map_x][map->camera.map_y] == '2')
			complete_sprite(map);
	}
}
