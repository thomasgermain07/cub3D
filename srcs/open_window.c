/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 11:29:27 by thgermai          #+#    #+#             */
/*   Updated: 2020/01/20 15:49:18 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub3d.h"

void		close_window(t_map *map)
{
	mlx_clear_window(map->mlx_param.mlx, map->mlx_param.window);
	mlx_destroy_image(map->mlx_param.mlx, map->mlx_param.window);
	exit(0);
}

int		(*get_img_addr(t_map *map))[][1]
{
	int		bit_per_pixel;
	int		size_line;
	int		endian;
	int		(*pixel_array)[map->resolution.x_res][1];
	char	*tmp;

	map->mlx_param.image = mlx_new_image(map->mlx_param.mlx,
		map->resolution.x_res, map->resolution.y_res);
	tmp = mlx_get_data_addr(map->mlx_param.image, &bit_per_pixel,
		&size_line, &endian);
	pixel_array = (void *)tmp;
	return (pixel_array);
}

void		moving(int direction, t_map *map)
{
	/* Need a button pressed and button released */
	if (direction == 1)
		map->player.x++;
	else if (direction == 13)
		map->player.x--;
	else if (direction == 0)
		map->player.y--;
	else if (direction == 2)
		map->player.y++;
	else if (direction == 123)
		;
	else if (direction == 124)
		;
}

int			key_center(int key, t_map *map)
{
	mlx_destroy_image(map->mlx_param.mlx, map->mlx_param.image);
	 if (key == 2 || key == 0 || key == 1 ||key == 13)
	 	moving(key, map);
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
	mlx_key_hook(map->mlx_param.window, key_center, map);
	mlx_loop(map->mlx_param.mlx);
}
