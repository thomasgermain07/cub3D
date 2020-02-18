/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utiles.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 14:57:30 by thgermai          #+#    #+#             */
/*   Updated: 2020/02/18 16:13:22 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	prepare_for_printing(t_map *map)
{
	if (!map->camera.side)
		map->camera.perp_wall_dist = fabs(((float)map->camera.map_x -
			map->camera.ray_pos_x + (1.0 - map->camera.step_x) /
			2.0) / map->camera.ray_dir_x);
	else
		map->camera.perp_wall_dist = fabs(((float)map->camera.map_y -
			map->camera.ray_pos_y + (1.0 - map->camera.step_y) / 2.0) /
			map->camera.ray_dir_y);
	map->camera.hauteur_ligne = (int)fabs(map->resolution.y_res /
		map->camera.perp_wall_dist);
	map->camera.draw_start = -map->camera.hauteur_ligne / 2 +
		map->resolution.y_res / 2;
	map->camera.draw_end = map->camera.hauteur_ligne / 2 +
		map->resolution.y_res / 2;
	if (map->camera.draw_start < 0)
		map->camera.draw_start = 0;
	if (map->camera.draw_end >= map->resolution.y_res)
		map->camera.draw_end = map->resolution.y_res - 1;
}

void	prepare_the_texture(t_map *map)
{
	if (map->camera.side)
		map->camera.wall_x = map->camera.ray_pos_x + (((float)map->camera.map_y
			- map->camera.ray_pos_y + (1.0 - map->camera.step_y) / 2.0) /
			map->camera.ray_dir_y) * map->camera.ray_dir_x;
	else
		map->camera.wall_x = map->camera.ray_pos_y + (((float)map->camera.map_x
			- map->camera.ray_pos_x + (1.0 - map->camera.step_x) / 2.0) /
			map->camera.ray_dir_x) * map->camera.ray_dir_y;
	map->camera.wall_x -= floor(map->camera.wall_x);
}

void	map_render(t_map *map, float buffer[map->resolution.x_res], int x)
{
	initiate_algo_value(map, x);
	get_ray_dir(map);
	check_for_hit(map);
	prepare_for_printing(map);
	prepare_the_texture(map);
	create_background(map, x);
	buffer[x] = map->camera.perp_wall_dist;
}
