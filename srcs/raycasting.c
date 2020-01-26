/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 08:56:48 by thgermai          #+#    #+#             */
/*   Updated: 2020/01/26 15:54:06 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	create_background(t_map *map, int x, int (*pixel_array)[map->resolution.x_res][1])
{
	int i;

	i = -1;
	while (++i < map->camera.draw_start)
		*pixel_array[i][x] = map->ceiling;
	i = map->camera.draw_end - 1;
	while (++i < map->resolution.y_res)
		*pixel_array[i][x] = map->ground;
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

void	raycasting(t_map *map)
{
	int		(*pixel_array)[map->resolution.x_res][1];
	int		x;

	x = 0;
	set_up_camera(map);
	pixel_array = get_img_addr(map);
	while (x <= map->resolution.x_res)
	{
		initiate_algo_value(map, x);
		get_ray_dir(map);
		check_for_hit(map);
		prepare_for_printing(map);
		prepare_the_texture(map);
		create_background(map, x, pixel_array);
		while (map->camera.draw_start < map->camera.draw_end)
		{
			get_the_color(map);
			if (map->camera.hit == 2) // -> hit a sprite
				map->camera.color = 16711680; // -> rouge
			*pixel_array[map->camera.draw_start++][x] = map->camera.color;
		}
		x++;
	}
	mlx_put_image_to_window(map->mlx_param.mlx, map->mlx_param.window,
		map->mlx_param.image, 0, 0);
}

