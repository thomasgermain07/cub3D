/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 10:48:50 by thgermai          #+#    #+#             */
/*   Updated: 2020/01/29 13:20:34 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	get_color_we(t_map *map)
{
	int		x;

	map->camera.tex_y = (map->camera.draw_start * 2 - map->resolution.y_res +
		map->camera.hauteur_ligne) * (map->texture.we.h / 2) /
		map->camera.hauteur_ligne;
	map->camera.tex_x = (int)(map->camera.wall_x * map->texture.we.w);
	map->camera.tex_x = map->texture.we.w - map->camera.tex_x - 1.0;
	x = (map->texture.we.w * map->camera.tex_y) + map->camera.tex_x;
	map->camera.color = map->texture.we.mapping[x];
}

void	get_color_ea(t_map *map)
{
	int		x;

	map->camera.tex_y = (map->camera.draw_start * 2 - map->resolution.y_res +
		map->camera.hauteur_ligne) * (map->texture.ea.h / 2) /
		map->camera.hauteur_ligne;
	map->camera.tex_x = (int)(map->camera.wall_x * map->texture.ea.w);
	map->camera.tex_x = map->texture.ea.w - map->camera.tex_x - 1.0;
	x = (map->texture.ea.w * map->camera.tex_y) + map->camera.tex_x;
	map->camera.color = map->texture.ea.mapping[x];
}

void	get_color_so(t_map *map)
{
	int		x;

	map->camera.tex_y = (map->camera.draw_start * 2 - map->resolution.y_res +
		map->camera.hauteur_ligne) * (map->texture.so.h / 2) /
		map->camera.hauteur_ligne;
	map->camera.tex_x = (int)(map->camera.wall_x * map->texture.so.w);
	map->camera.tex_x = map->texture.so.w - map->camera.tex_x - 1.0;
	x = (map->texture.so.w * map->camera.tex_y) + map->camera.tex_x;
	map->camera.color = map->texture.so.mapping[x];
}

void	get_color_no(t_map *map)
{
	int		x;

	map->camera.tex_y = (map->camera.draw_start * 2 - map->resolution.y_res +
		map->camera.hauteur_ligne) * (map->texture.no.h / 2) /
		map->camera.hauteur_ligne;
	map->camera.tex_x = (int)(map->camera.wall_x * map->texture.no.w);
	map->camera.tex_x = map->texture.no.w - map->camera.tex_x - 1.0;
	x = (map->texture.no.w * map->camera.tex_y) + map->camera.tex_x;
	map->camera.color = map->texture.no.mapping[x];
}

void	get_color_s(t_map *map)
{
	int		x;

	map->camera.tex_y = (map->camera.draw_start * 2 - map->resolution.y_res +
		map->camera.hauteur_ligne) * (map->texture.s.h / 2) / map->camera.hauteur_ligne;
	map->camera.tex_x = (int)(map->camera.wall_x * map->texture.s.w);
	map->camera.tex_x = map->texture.s.w - map->camera.tex_x - 1.0;
	x = (map->texture.s.w * map->camera.tex_y) + map->camera.tex_x;
	map->camera.color = map->texture.s.mapping[x];

}

void	get_the_color(t_map *map)
{
	if (map->camera.hit == 2) // THIS IS A FUCKIIIIING SPRITE
		get_color_s(map);
	else if (!map->camera.side && map->camera.ray_dir_x > 0 &&
		map->camera.hit == 1) // Orientation nord
		get_color_no(map);
	else if (!map->camera.side && map->camera.ray_dir_x < 0 &&
		 map->camera.hit == 1) // Orientation sud
		get_color_so(map);
	else if (map->camera.side && map->camera.ray_dir_y > 0 &&
		map->camera.hit == 1) // Orientation west
		get_color_we(map);
	else // Orientation east
		get_color_ea(map);
}
