/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 12:38:52 by thgermai          #+#    #+#             */
/*   Updated: 2020/01/21 14:33:18 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		move_foward(t_map *map)
{
	ft_printf("here i move foward\n");
	if (map->plan.plan[(int)(map->player.x + map->camera.dir_x * MV_SPEED)][(int)map->player.y] != '1')
		map->player.x += map->camera.dir_x * MV_SPEED;
	if (map->plan.plan[(int)map->player.x][(int)(map->player.y + map->camera.dir_y * MV_SPEED)] != '1')
		map->player.y += map->camera.dir_y * MV_SPEED;
}

void		move_backward(t_map *map)
{
	ft_printf("here i move backward\n");
	if (map->plan.plan[(int)(map->player.x - map->camera.dir_x * MV_SPEED)][(int)map->player.y] != '1')
		map->player.x -= map->camera.dir_x * MV_SPEED;
	if (map->plan.plan[(int)map->player.x][(int)(map->player.y - map->camera.dir_y * MV_SPEED)] != '1')
		map->player.y -= map->camera.dir_y * MV_SPEED;
}

void		move_left(t_map *map)
{
	ft_printf("here i move left\n");
	if (map->plan.plan[(int)(map->player.x - map->camera.plan_x * MV_SPEED)][(int)map->player.y] != '1')
		map->player.x -= map->camera.plan_x * MV_SPEED;
	if (map->plan.plan[(int)map->player.x][(int)(map->player.y - map->camera.plan_y * MV_SPEED)] != '1')
		map->player.y -= map->camera.plan_y * MV_SPEED;
}

void		move_right(t_map *map)
{
	ft_printf("here i move right\n");
	if (map->plan.plan[(int)(map->player.x + map->camera.plan_x * MV_SPEED)][(int)map->player.y] != '1')
		map->player.x += map->camera.plan_x * MV_SPEED;
	if (map->plan.plan[(int)map->player.x][(int)(map->player.y + map->camera.plan_y * MV_SPEED)] != '1')
		map->player.y += map->camera.plan_y * MV_SPEED;
}

void		turn_left(t_map *map)
{
	float old_dir_x;
	float old_plan_x;

	ft_printf("here i turn left\n");
	old_dir_x = map->player.dir_x;
	map->player.dir_x = map->player.dir_x * cos(-ROT_SPEED) - map->player.dir_y * sin(-ROT_SPEED);
	map->player.dir_y = old_dir_x * sin(-ROT_SPEED) + map->player.dir_y * cos(-ROT_SPEED);
	old_plan_x = map->camera.plan_x;
	map->camera.plan_x = map->camera.plan_x * cos(-ROT_SPEED) - map->camera.plan_y * sin(-ROT_SPEED);
	map->camera.plan_y = old_plan_x * sin(-ROT_SPEED) + map->camera.plan_y * cos(-ROT_SPEED);
}

void		turn_right(t_map *map)
{
	float old_dir_x;
	float old_plan_x;

	ft_printf("here i turn left\n");
	old_dir_x = map->player.dir_x;
	map->player.dir_x = map->player.dir_x * cos(ROT_SPEED) - map->player.dir_y * sin(ROT_SPEED);
	map->player.dir_y = old_dir_x * sin(ROT_SPEED) + map->player.dir_y * cos(ROT_SPEED);
	old_plan_x = map->camera.plan_x;
	map->camera.plan_x = map->camera.plan_x * cos(-ROT_SPEED) - map->camera.plan_y * sin(ROT_SPEED);
	map->camera.plan_y = old_plan_x * sin(ROT_SPEED) + map->camera.plan_y * cos(ROT_SPEED);
}
