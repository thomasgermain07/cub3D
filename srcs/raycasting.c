/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 08:56:48 by thgermai          #+#    #+#             */
/*   Updated: 2020/02/10 14:43:35 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_put_pixel(t_map *map, int x, int y, unsigned int color)
{
	int		(*pixel_array)[map->resolution.x_res][1];

	pixel_array = (void *)map->mlx_param.mapping;
	*pixel_array[x][y] = color;
}

void	create_background(t_map *map, int x)
{
	int i;

	i = -1;
	while (++i < map->camera.draw_start)
		ft_put_pixel(map, i, x, map->ceiling);
	i = map->camera.draw_end - 1;
	while (++i < map->resolution.y_res)
		ft_put_pixel(map, i, x, map->ground);
}

void		create_image(t_map *map)
{
	int		bit_per_pixel;
	int		size_line;
	int		endian;

	map->mlx_param.image = mlx_new_image(map->mlx_param.mlx,
		map->resolution.x_res, map->resolution.y_res);
	map->mlx_param.mapping = mlx_get_data_addr(map->mlx_param.image,
		&bit_per_pixel, &size_line, &endian);
}

void	raycasting(t_map *map)
{
	float		buffer[map->resolution.x_res];
	int			x;

	x = -1;
	set_up_camera(map);
	create_image(map);
	calcul_sprite_dist(map);
	sort_sprite(map);
	while (++x < map->resolution.x_res)
	{
		map_render(map, buffer, x);
		while (map->camera.draw_start < map->camera.draw_end)
		{
			get_the_color(map);
			ft_put_pixel(map, map->camera.draw_start++, x, map->camera.color);
		}
	}
	sprite_render(map, buffer);
	mlx_put_image_to_window(map->mlx_param.mlx, map->mlx_param.window,
		map->mlx_param.image, 0, 0);
}
