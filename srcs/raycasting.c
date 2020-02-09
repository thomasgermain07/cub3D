/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 08:56:48 by thgermai          #+#    #+#             */
/*   Updated: 2020/02/09 18:45:19 by thgermai         ###   ########.fr       */
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

void	sprite_render(t_map *map)
{
	t_list		*lst;
	t_sprite	*sprite;

	lst = *map->sprite;
	while (lst)
	{
		sprite = lst->content;
		if (sprite->visible)
		{
			sprite->sprite_x = sprite->x - map->player.x;
			sprite->sprite_y = sprite->y - map->player.y;
			sprite->inv_det = 1.0 / (map->camera.plan_x * map->player.dir_y - map->player.dir_x * map->camera.plan_y);
			sprite->trans_x = sprite->inv_det * (map->player.dir_y * sprite->sprite_x - map->player.dir_x * sprite->sprite_y);
			sprite->trans_y = sprite->inv_det * (-map->camera.plan_y * sprite->sprite_x + map->camera.plan_x * sprite->sprite_y);
			sprite->screen_x = (map->resolution.x_res / 2) * (1.0 + sprite->trans_x / sprite->trans_y);
			sprite->height = (int)fabs(map->resolution.x_res / sprite->trans_y);
			if ((sprite->draw_start_y = -sprite->height / 2 + map->resolution.y_res / 2) < 0)
				sprite->draw_start_y = 0;
			if ((sprite->draw_end_y = sprite->height / 2 + map->resolution.y_res / 2) >= map->resolution.y_res)
				sprite->draw_end_y = map->resolution.y_res - 1;
			sprite->width = (int)fabs(map->resolution.x_res / sprite->trans_y);
			if ((sprite->draw_start_x = -sprite->width / 2 + sprite->screen_x) < 0)
				sprite->draw_start_x = 0;
			if ((sprite->draw_end_x = sprite->width / 2 + sprite->screen_x) >= map->resolution.x_res)
				sprite->draw_end_x = map->resolution.x_res - 1;
		}
		lst = lst->next;
	}
}

void	test_color(t_sprite *sprite, t_image *texture)
{
	int x;

	sprite->wall_x = (sprite->stripe - sprite->draw_start_x) / (sprite->draw_end_x - sprite->draw_start_x);
	sprite->wall_y = (sprite->pix - sprite->draw_start_y) / (sprite->draw_end_y - sprite->draw_end_y);
	printf("%f %f\n", sprite->wall_x, sprite->wall_y);
	sprite->tex_x = sprite->wall_x * texture->w;
	sprite->tex_y = sprite->wall_y * texture->h;
	x = sprite->tex_y * texture->h + sprite->tex_x;
	sprite->color = texture->mapping[x];
}

void	raycasting(t_map *map)
{
	int			(*pixel_array)[map->resolution.x_res][1];
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
				while (++sprite->pix < sprite->draw_end_y)
				{
				//	get_sprite_color(map, &map->texture.s, sprite);
					test_color(sprite, &map->texture.s);
					if (sprite->color != 0xff000000)
						*pixel_array[sprite->pix][sprite->stripe] = sprite->color;
					// else
					// 	*pixel_array[sprite->pix][sprite->stripe] = 0xFFFFFF;
				}
			}
		}
		lst = lst->next;
	}
	mlx_put_image_to_window(map->mlx_param.mlx, map->mlx_param.window,
		map->mlx_param.image, 0, 0);
}
