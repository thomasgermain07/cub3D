/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 08:56:48 by thgermai          #+#    #+#             */
/*   Updated: 2020/01/23 18:07:31 by thgermai         ###   ########.fr       */
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
	int		(*tex_array)[map->texture.no.w][1];
	int		x;

	float	wall_x;
	float	tex_x;
	int		tex_y;
	int		color;

	x = 0;
	set_up_camera(map);
	pixel_array = get_img_addr(map);
	create_background(map, map->resolution.x_res, pixel_array);
	while (x <= map->resolution.x_res)
	{
		initiate_algo_value(map, x);
		get_ray_dir(map);
		check_for_hit(map);
		prepare_for_printing(map);
		// start texture //
		if (map->camera.side == 1)
			wall_x = map->camera.ray_pos_x + (((float)map->camera.map_y - map->camera.ray_pos_y + (1.0 - map->camera.step_y) / 2.0) / map->camera.ray_dir_y) * map->camera.ray_dir_x;
 		else
			wall_x = map->camera.ray_pos_y + (((float)map->camera.map_x - map->camera.ray_pos_x + (1.0 - map->camera.step_x) / 2.0) / map->camera.ray_dir_x) * map->camera.ray_dir_y;
		wall_x -= floor(wall_x);
		tex_x = (int)(wall_x * map->texture.no.w);
		if ((!map->camera.side && map->camera.ray_dir_x > 0) || (map->camera.side == 1 && map->camera.ray_dir_y < 0))
			tex_x = map->texture.no.w - tex_x - 1.0;
		while (map->camera.draw_start < map->camera.draw_end)
		{
			tex_y = (map->camera.draw_start * 2 - map->resolution.y_res + map->camera.hauteur_ligne) * (map->texture.no.h / 2) / map->camera.hauteur_ligne;
			if (map->camera.hit == 2)
				color = 16711680;
			else if (map->camera.hit == 1)
			{
				tex_array = (void *)map->texture.no.image;
				color = *tex_array[(int)tex_y][(int)tex_x];
			}
			else if (map->camera.hit == 1)
			{
				tex_array = (void *)map->texture.so.image;
				color = *tex_array[(int)tex_y][(int)tex_x];
			}
			*pixel_array[map->camera.draw_start++][x] = color;
		}
		x++;
	}
	mlx_put_image_to_window(map->mlx_param.mlx, map->mlx_param.window,
		map->mlx_param.image, 0, 0);
}

