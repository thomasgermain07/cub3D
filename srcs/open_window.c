/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 11:29:27 by thgermai          #+#    #+#             */
/*   Updated: 2020/02/26 13:12:29 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			close_window(t_map *map)
{
	del_mlx_data(map, 1);
	ft_lstclear(map->sprite, free);
	ft_free_ptrlst(map->ptr_lst);
	exit(0);
}

int			key_push(int key, t_map *map)
{
	if (key == 0)
		map->player.movement.left = 1;
	else if (key == 1)
		map->player.movement.backward = 1;
	else if (key == 2)
		map->player.movement.right = 1;
	else if (key == 13)
		map->player.movement.forward = 1;
	else if (key == 123)
		map->player.movement.turn_left = 1;
	else if (key == 124)
		map->player.movement.turn_right = 1;
	if (key == 257)
	{
		map->player.movement.mv_speed = map->player.movement.former_mv_speed *
			2;
		map->player.movement.rot_speed = map->player.movement.former_rot_speed *
			1.5;
	}
	if (key == 15)
		respaw_sprite(map);
	if (key == 53)
		close_window(map);
	return (0);
}

int			key_release(int key, t_map *map)
{
	if (key == 0)
		map->player.movement.left = 0;
	else if (key == 1)
		map->player.movement.backward = 0;
	else if (key == 2)
		map->player.movement.right = 0;
	else if (key == 13)
		map->player.movement.forward = 0;
	else if (key == 123)
		map->player.movement.turn_left = 0;
	else if (key == 124)
		map->player.movement.turn_right = 0;
	if (key == 257)
	{
		map->player.movement.mv_speed = map->player.movement.former_mv_speed;
		map->player.movement.rot_speed = map->player.movement.former_rot_speed;
	}
	return (0);
}

int			key_center(t_map *map)
{
	mlx_clear_window(map->mlx_param.mlx, map->mlx_param.window);
	if (map->player.movement.left)
		move_left(map);
	else if (map->player.movement.right)
		move_right(map);
	if (map->player.movement.forward)
		move_foward(map);
	else if (map->player.movement.backward)
		move_backward(map);
	if (map->player.movement.turn_left)
		turn_left(map);
	else if (map->player.movement.turn_right)
		turn_right(map);
	raycasting(map);
	mlx_put_image_to_window(map->mlx_param.mlx, map->mlx_param.window,
		map->mlx_param.image, 0, 0);
	return (0);
}

void		open_window(t_map *map)
{
	if (!map->mlx_param.mlx)
		map->mlx_param.mlx = mlx_init();
	get_all_texture(map);
	map->player.movement.former_mv_speed = MV_SPEED;
	map->player.movement.former_rot_speed = ROT_SPEED;
	map->player.movement.mv_speed = MV_SPEED;
	map->player.movement.rot_speed = ROT_SPEED;
	if (!map->mlx_param.window)
		map->mlx_param.window = mlx_new_window(map->mlx_param.mlx,
		map->resolution.x_res, map->resolution.y_res, "cub3D");
	raycasting(map);
	mlx_hook(map->mlx_param.window, 2, (1L << 0), &key_push, map);
	mlx_hook(map->mlx_param.window, 3, (1l << 1), &key_release, map);
	mlx_hook(map->mlx_param.window, 17, (1l << 1), &close_window, map);
	mlx_loop_hook(map->mlx_param.mlx, &key_center, map);
	mlx_loop(map->mlx_param.mlx);
}
