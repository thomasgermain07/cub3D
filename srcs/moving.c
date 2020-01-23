/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 12:38:52 by thgermai          #+#    #+#             */
/*   Updated: 2020/01/23 14:40:43 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		move_foward(t_map *map)
{
	//ft_printf("here i move foward\n");
	if (map->plan.plan[(int)(map->player.x + map->camera.dir_x * map->player.movement.mv_speed)][(int)map->player.y] != '1')
		map->player.x += map->camera.dir_x * map->player.movement.mv_speed;
	if (map->plan.plan[(int)map->player.x][(int)(map->player.y + map->camera.dir_y * map->player.movement.mv_speed)] != '1')
		map->player.y += map->camera.dir_y * map->player.movement.mv_speed;
	if (map->plan.plan[(int)map->player.x][(int)map->player.y] == '2')
	{
		ft_printf("\n\nSPRITE COLLECTED\nstill : %d\n\n", --map->plan.sprite_nb);
		map->plan.plan[(int)map->player.x][(int)map->player.y] = '0';
	}
}

void		move_backward(t_map *map)
{
	//ft_printf("here i move backward\n");
	if (map->plan.plan[(int)(map->player.x - map->camera.dir_x * map->player.movement.mv_speed)][(int)map->player.y] != '1')
		map->player.x -= map->camera.dir_x * map->player.movement.mv_speed;
	if (map->plan.plan[(int)map->player.x][(int)(map->player.y - map->camera.dir_y * map->player.movement.mv_speed)] != '1')
		map->player.y -= map->camera.dir_y * map->player.movement.mv_speed;
	if (map->plan.plan[(int)map->player.x][(int)map->player.y] == '2')
	{
		ft_printf("\n\nSPRITE COLLECTED\nstill : %d\n\n", --map->plan.sprite_nb);
		map->plan.plan[(int)map->player.x][(int)map->player.y] = '0';
	}
}

void		move_left(t_map *map)
{
//	ft_printf("here i move left\n");
	if (map->plan.plan[(int)(map->player.x - map->camera.plan_x * map->player.movement.mv_speed)][(int)map->player.y] != '1')
		map->player.x -= map->camera.plan_x * map->player.movement.mv_speed;
	if (map->plan.plan[(int)map->player.x][(int)(map->player.y - map->camera.plan_y * map->player.movement.mv_speed)] != '1')
		map->player.y -= map->camera.plan_y * map->player.movement.mv_speed;
	if (map->plan.plan[(int)map->player.x][(int)map->player.y] == '2')
	{
		ft_printf("\n\nSPRITE COLLECTED\nstill : %d\n\n", --map->plan.sprite_nb);
		map->plan.plan[(int)map->player.x][(int)map->player.y] = '0';
	}
}

void		move_right(t_map *map)
{
	//ft_printf("here i move right\n");
	if (map->plan.plan[(int)(map->player.x + map->camera.plan_x * map->player.movement.mv_speed)][(int)map->player.y] != '1')
		map->player.x += map->camera.plan_x * map->player.movement.mv_speed;
	if (map->plan.plan[(int)map->player.x][(int)(map->player.y + map->camera.plan_y * map->player.movement.mv_speed)] != '1')
		map->player.y += map->camera.plan_y * map->player.movement.mv_speed;
	if (map->plan.plan[(int)map->player.x][(int)map->player.y] == '2')
	{
		ft_printf("\n\nSPRITE COLLECTED\nstill : %d\n\n", --map->plan.sprite_nb);
		map->plan.plan[(int)map->player.x][(int)map->player.y] = '0';
	}
}

void		turn_left(t_map *map)
{
	float old_dir_x;
	float old_plan_x;

	//ft_printf("here i turn left\n");
	old_dir_x = map->player.dir_x;
	map->player.dir_x = map->player.dir_x * cos(map->player.movement.rot_speed) - map->player.dir_y * sin(map->player.movement.rot_speed);
	map->player.dir_y = old_dir_x * sin(map->player.movement.rot_speed) + map->player.dir_y * cos(map->player.movement.rot_speed);
	old_plan_x = map->camera.plan_x;
	map->camera.plan_x = map->camera.plan_x * cos(map->player.movement.rot_speed) - map->camera.plan_y * sin(map->player.movement.rot_speed);
	map->camera.plan_y = old_plan_x * sin(map->player.movement.rot_speed) + map->camera.plan_y * cos(map->player.movement.rot_speed);
}

void		turn_right(t_map *map)
{
	float old_dir_x;
	float old_plan_x;

	//ft_printf("here i turn right\n");
	old_dir_x = map->player.dir_x;
	map->player.dir_x = map->player.dir_x * cos(-map->player.movement.rot_speed) - map->player.dir_y * sin(-map->player.movement.rot_speed);
	map->player.dir_y = old_dir_x * sin(-map->player.movement.rot_speed) + map->player.dir_y * cos(-map->player.movement.rot_speed);
	old_plan_x = map->camera.plan_x;
	map->camera.plan_x = map->camera.plan_x * cos(-map->player.movement.rot_speed) - map->camera.plan_y * sin(-map->player.movement.rot_speed);
	map->camera.plan_y = old_plan_x * sin(-map->player.movement.rot_speed) + map->camera.plan_y * cos(-map->player.movement.rot_speed);
}
