/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 12:38:52 by thgermai          #+#    #+#             */
/*   Updated: 2020/02/10 16:39:18 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		move_foward(t_map *map)
{
	if (map->plan.plan[(int)(map->player.x + map->player.dir_x *
		map->player.movement.mv_speed)][(int)map->player.y] != '1')
		map->player.x += map->player.dir_x * map->player.movement.mv_speed;
	if (map->plan.plan[(int)map->player.x][(int)(map->player.y +
		map->player.dir_y * map->player.movement.mv_speed)] != '1')
		map->player.y += map->player.dir_y * map->player.movement.mv_speed;
	if (map->plan.plan[(int)map->player.x][(int)map->player.y] == '2')
	{
		map->plan.sprite_collected++;
		map->plan.plan[(int)map->player.x][(int)map->player.y] = '0';
	}
}

void		move_backward(t_map *map)
{
	if (map->plan.plan[(int)(map->player.x - map->player.dir_x *
		map->player.movement.mv_speed)][(int)map->player.y] != '1')
		map->player.x -= map->player.dir_x * map->player.movement.mv_speed;
	if (map->plan.plan[(int)map->player.x][(int)(map->player.y -
		map->player.dir_y * map->player.movement.mv_speed)] != '1')
		map->player.y -= map->player.dir_y * map->player.movement.mv_speed;
	if (map->plan.plan[(int)map->player.x][(int)map->player.y] == '2')
	{
		map->plan.sprite_collected++;
		map->plan.plan[(int)map->player.x][(int)map->player.y] = '0';
	}
}

void		move_left(t_map *map)
{
	if (map->plan.plan[(int)(map->player.x - map->camera.plan_x *
		map->player.movement.mv_speed)][(int)map->player.y] != '1')
		map->player.x -= map->camera.plan_x * map->player.movement.mv_speed;
	if (map->plan.plan[(int)map->player.x][(int)(map->player.y -
		map->camera.plan_y * map->player.movement.mv_speed)] != '1')
		map->player.y -= map->camera.plan_y * map->player.movement.mv_speed;
	if (map->plan.plan[(int)map->player.x][(int)map->player.y] == '2')
	{
		map->plan.sprite_collected++;
		map->plan.plan[(int)map->player.x][(int)map->player.y] = '0';
	}
}

void		move_right(t_map *map)
{
	if (map->plan.plan[(int)(map->player.x + map->camera.plan_x *
		map->player.movement.mv_speed)][(int)map->player.y] != '1')
		map->player.x += map->camera.plan_x * map->player.movement.mv_speed;
	if (map->plan.plan[(int)map->player.x][(int)(map->player.y +
		map->camera.plan_y * map->player.movement.mv_speed)] != '1')
		map->player.y += map->camera.plan_y * map->player.movement.mv_speed;
	if (map->plan.plan[(int)map->player.x][(int)map->player.y] == '2')
	{
		map->plan.sprite_collected++;
		map->plan.plan[(int)map->player.x][(int)map->player.y] = '0';
	}
}
