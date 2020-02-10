/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 08:56:48 by thgermai          #+#    #+#             */
/*   Updated: 2020/02/10 10:55:03 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	create_background(t_map *map, int x,
	int (*pixel_array)[map->resolution.x_res][1])
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

// void	ft_put_pixel(t_map *map, int x, int y, unsigned int color)
// {
// 	int		(*pixel_array)[map->resolution.x_res][1];

// 	pixel_array = (void *)map->mlx_param.image;
// }

void	raycasting(t_map *map)
{
	int			(*pixel_array)[map->resolution.x_res][1];
	float		buffer[map->resolution.x_res];
	int			x;
	t_list		*lst;
	t_sprite	*sprite;

	x = -1;
	set_up_camera(map);
	pixel_array = get_img_addr(map);
	calcul_sprite_dist(map);
	sort_sprite(map);
	while (++x < map->resolution.x_res)
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
			*pixel_array[map->camera.draw_start++][x] = map->camera.color;
		}
		buffer[x] = map->camera.perp_wall_dist;
	}
	sprite_render(map);
	lst = *map->sprite;
	while (lst)
	{
		sprite = lst->content;
		if (sprite->visible)
		{
			sprite->stripe = sprite->draw_start_x - 1;
			while (++sprite->stripe < sprite->draw_end_x)
			{
				sprite->pix = sprite->draw_start_y - 1;
				if (sprite->trans_y < buffer[sprite->stripe])
				{
					while (++sprite->pix < sprite->draw_end_y)
					{
						if (sprite->stripe >= 0 && sprite->stripe < map->resolution.x_res)
						{
							get_sprite_color(map, &map->texture.s, sprite);
							if (sprite->color != 0xff000000)
								*pixel_array[sprite->pix][sprite->stripe] = sprite->color;
						}
					}
				}
			}
		}
		lst = lst->next;
	}
	mlx_put_image_to_window(map->mlx_param.mlx, map->mlx_param.window,
		map->mlx_param.image, 0, 0);
}
