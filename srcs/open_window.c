/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 11:29:27 by thgermai          #+#    #+#             */
/*   Updated: 2020/01/21 16:39:16 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub3d.h"

int			close_window(t_map *map)
{
	int i;

	i = 0;
	mlx_clear_window(map->mlx_param.mlx, map->mlx_param.window);
	mlx_destroy_image(map->mlx_param.mlx, map->mlx_param.window);
	while (map->plan.plan[i])
		free(map->plan.plan[i++]);
	free(map);
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
		map->player.movement.foward = 1;
	else if (key == 124)
		map->player.movement.turn_left = 1;
	else if (key == 123)
		map->player.movement.turn_right = 1;
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
		map->player.movement.foward = 0;
	else if (key == 124)
		map->player.movement.turn_left = 0;
	else if (key == 123)
		map->player.movement.turn_right = 0;
	return (0);
}

int			key_center(t_map *map)
{
	if (map->player.movement.left)
		move_left(map);
	else if (map->player.movement.right)
		move_right(map);
	if (map->player.movement.foward)
		move_foward(map);
	else if (map->player.movement.backward)
		move_backward(map);
	if (map->player.movement.turn_left)
		turn_left(map);
	else if (map->player.movement.turn_right)
		turn_right(map);
	raycasting(map);
	mlx_destroy_image(map->mlx_param.mlx, map->mlx_param.image);
	return (0);
}

/* Quand spawn E ou W erreur de turn direction */
void		open_window(t_map *map)
{
	map->mlx_param.mlx = mlx_init();
	map->mlx_param.window = mlx_new_window(map->mlx_param.mlx,
		map->resolution.x_res, map->resolution.y_res, "Cub3d");
	raycasting(map);
	mlx_do_key_autorepeatoff(map->mlx_param.mlx);
	mlx_hook(map->mlx_param.window, 2, (1L<<0), &key_push, map);
	mlx_hook(map->mlx_param.window, 3, (1l<<1), &key_release, map);
	mlx_hook(map->mlx_param.window, 17, (1l<<1), &close_window, map);
	mlx_loop_hook(map->mlx_param.mlx, &key_center, map);
	mlx_loop(map->mlx_param.mlx);
}
