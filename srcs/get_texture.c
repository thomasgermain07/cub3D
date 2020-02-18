/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 08:53:15 by thgermai          #+#    #+#             */
/*   Updated: 2020/02/18 15:39:02 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	get_sprite_color(t_map *map, t_image *texture, t_sprite *sprite)
{
	int x;

	sprite->wall_x = (float)(sprite->stripe - sprite->draw_start_x) /
		(float)(sprite->draw_end_x - sprite->draw_start_x);
	sprite->tex_y = (sprite->pix * 2 - map->resolution.y_res +
		sprite->height) * (texture->h / 2) / sprite->height;
	sprite->tex_x = (int)(sprite->wall_x * texture->w);
	sprite->tex_x = texture->w - sprite->tex_x - 1.0;
	x = (texture->w * sprite->tex_y) + sprite->tex_x;
	sprite->color = texture->mapping[x];
}

void	get_tex_color(t_map *map, t_image *texture)
{
	int	x;

	map->camera.tex_y = (map->camera.draw_start * 2 - map->resolution.y_res +
		map->camera.hauteur_ligne) * (texture->h / 2) /
		map->camera.hauteur_ligne;
	map->camera.tex_x = (int)(map->camera.wall_x * texture->w);
	map->camera.tex_x = texture->w - map->camera.tex_x - 1.0;
	x = (texture->w * map->camera.tex_y) + map->camera.tex_x;
	map->camera.color = texture->mapping[x];
}

void	get_the_color(t_map *map)
{
	if (!map->camera.side && map->camera.ray_dir_x > 0)
		get_tex_color(map, &map->texture.no);
	else if (!map->camera.side && map->camera.ray_dir_x < 0)
		get_tex_color(map, &map->texture.so);
	else if (map->camera.side && map->camera.ray_dir_y > 0)
		get_tex_color(map, &map->texture.we);
	else if (map->camera.side && map->camera.ray_dir_y < 0)
		get_tex_color(map, &map->texture.ea);
}

void	get_texture(t_image *texture, t_map *map)
{
	int		x;
	int		y;
	int		bit_per_pixel;

	if (!(texture->image = mlx_xpm_file_to_image(map->mlx_param.mlx,
		texture->name, &texture->w, &texture->h)))
	{
		ft_printf(ERR_TEXTURE_PATH, texture->name);
		close_window(map);
	}
	texture->mapping = (int *)mlx_get_data_addr(texture->image,
		&x, &y, &bit_per_pixel);
}

void	get_all_texture(t_map *map)
{
	get_texture(&map->texture.no, map);
	get_texture(&map->texture.so, map);
	get_texture(&map->texture.ea, map);
	get_texture(&map->texture.we, map);
	get_texture(&map->texture.s, map);
}
