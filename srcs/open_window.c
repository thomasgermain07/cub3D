/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 11:29:27 by thgermai          #+#    #+#             */
/*   Updated: 2020/01/21 13:55:24 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub3d.h"

void		close_window(t_map *map)
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

int			key_center(int key, t_map *map)
{
	ft_printf("here we are bro");
	mlx_destroy_image(map->mlx_param.mlx, map->mlx_param.image);
	if (key == 0)
		move_left(map);
	else if (key == 1)
		move_backward(map);
	else if (key == 2)
		move_left(map);
	else if (key == 13)
		move_foward(map);
	else if (key == 123)
		turn_left(map);
	else if (key == 124)
		turn_right(map);
	if (key == 53)
		close_window(map);
	raycasting(map);
	return (0);
}

void		open_window(t_map *map)
{
	map->mlx_param.mlx = mlx_init();
	map->mlx_param.window = mlx_new_window(map->mlx_param.mlx,
		map->resolution.x_res, map->resolution.y_res, "Cub3d");
	raycasting(map);
	mlx_hook(map->mlx_param.window, 2, (1L<<0), key_push, map);
	mlx_hook(map->mlx_param.window, 3 (1l<<1), key_release,  )
	mlx_key_hook(map->mlx_param.window, key_center, map);
	mlx_loop(map->mlx_param.mlx);
}
