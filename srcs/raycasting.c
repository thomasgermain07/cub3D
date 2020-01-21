/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 08:56:48 by thgermai          #+#    #+#             */
/*   Updated: 2020/01/21 12:59:18 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	create_background(t_map *map, int size, int (*pixel_array)[size][1])
{
	int		i;
	int		j;

	i = 0;
	while (i < map->resolution.y_res / 2)
	{
		j = 0;
		while (j < map->resolution.x_res)
			*pixel_array[i][j++] = map->ceiling;
		i++;
	}
	while (i < map->resolution.y_res)
	{
		j = 0;
		while (j < map->resolution.x_res)
			*pixel_array[i][j++] = map->ground;
		i++;
	}
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
	int		color; // -> will be replaced by the texture

	x = 0;
	set_up_camera(map);
	pixel_array = get_img_addr(map);
	create_background(map, map->resolution.x_res, pixel_array);
	ft_printf("%d %d\n", map->player.x, map->player.y);
	while (x <= map->resolution.x_res)
	{
		initiate_algo_value(map, x);
		get_ray_dir(map);
		while (!map->camera.hit)
			check_for_hit(map);
		prepare_for_printing(map);
		color = 16443110;
		if (map->camera.side == 1)
			color = 11119017;
		while (map->camera.draw_start < map->camera.draw_end)
			*pixel_array[map->camera.draw_start++][x] = color;
		x++;
	}
	mlx_put_image_to_window(map->mlx_param.mlx, map->mlx_param.window,
		map->mlx_param.image, 0, 0);
}
