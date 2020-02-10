/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 11:21:13 by thgermai          #+#    #+#             */
/*   Updated: 2020/02/10 11:21:43 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		turn_left(t_map *map)
{
	float old_dir_x;
	float old_plan_x;

	old_dir_x = map->player.dir_x;
	map->player.dir_x = map->player.dir_x * cos(map->player.movement.rot_speed)
		- map->player.dir_y * sin(map->player.movement.rot_speed);
	map->player.dir_y = old_dir_x * sin(map->player.movement.rot_speed) +
		map->player.dir_y * cos(map->player.movement.rot_speed);
	old_plan_x = map->camera.plan_x;
	map->camera.plan_x = map->camera.plan_x *
		cos(map->player.movement.rot_speed) - map->camera.plan_y *
		sin(map->player.movement.rot_speed);
	map->camera.plan_y = old_plan_x * sin(map->player.movement.rot_speed) +
		map->camera.plan_y * cos(map->player.movement.rot_speed);
}

void		turn_right(t_map *map)
{
	float old_dir_x;
	float old_plan_x;

	old_dir_x = map->player.dir_x;
	map->player.dir_x = map->player.dir_x * cos(-map->player.movement.rot_speed)
		- map->player.dir_y * sin(-map->player.movement.rot_speed);
	map->player.dir_y = old_dir_x * sin(-map->player.movement.rot_speed) +
		map->player.dir_y * cos(-map->player.movement.rot_speed);
	old_plan_x = map->camera.plan_x;
	map->camera.plan_x = map->camera.plan_x *
		cos(-map->player.movement.rot_speed) - map->camera.plan_y *
		sin(-map->player.movement.rot_speed);
	map->camera.plan_y = old_plan_x * sin(-map->player.movement.rot_speed) +
		map->camera.plan_y * cos(-map->player.movement.rot_speed);
}
