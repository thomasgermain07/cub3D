/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 08:56:48 by thgermai          #+#    #+#             */
/*   Updated: 2020/02/10 16:47:38 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		ft_put_pixel(t_map *map, int x, int y, unsigned int color)
{
	int		(*pixel_array)[map->resolution.x_res][1];

	pixel_array = (void *)map->mlx_param.mapping;
	*pixel_array[x][y] = color;
}

void		create_background(t_map *map, int x)
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

void		hud_render(t_map *map)
{
	float		x;
	float		y;
	float		height;
	float		width;
	float		start_x;
	float		end_x;
	float		start_y;
	float		end_y;

	start_x = (map->resolution.x_res / 16) * 5;
	start_y = (map->resolution.y_res / 16) * 15;

	width = (map->resolution.x_res / 16) * 6;
	height = (map->resolution.y_res / 16) * 1;

	end_x = start_x + width;
	end_y = start_y + height;

	x = start_x - 1;
	while (++x < end_x)
	{
		y = start_y - 1;
		while (++y < end_y)
		{
			if (map->plan.sprite_nb && (x - start_x) / (end_x - start_x) >
				(float)map->plan.sprite_collected / (float)map->plan.sprite_nb)
				ft_put_pixel(map, y, x, 0xFFFFFF);
			else
				ft_put_pixel(map, y, x, 0xFFFFF);
		}
	}
}

void		raycasting(t_map *map)
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
	hud_render(map);
	mlx_put_image_to_window(map->mlx_param.mlx, map->mlx_param.window,
		map->mlx_param.image, 0, 0);
}
