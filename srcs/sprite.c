/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 15:24:19 by thgermai          #+#    #+#             */
/*   Updated: 2020/02/02 14:38:55 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	calcul_sprite_dist(t_map *map)
{
	float		x;
	float		y;
	t_sprite	*sprite;
	t_list		*lst;

	sprite = NULL;
	lst = *map->sprite;
	while (lst)
	{
		sprite = (t_sprite *)lst->content;
		x = fabs(powf(map->player.x - (float)sprite->x, 2.0));
		y = fabs(powf(map->player.y - (float)sprite->y, 2.0));
		sprite->distance = sqrtf(x + y);
		lst = lst->next;
	}
}

void		sort_sprite(t_map *map)
{
	void		*temp;
	t_list		*current;
	t_list		*origin;
	t_sprite	*first;
	t_sprite	*second;

	origin = *map->sprite;
	current = *map->sprite;
	while (current && current->next)
	{
		first = current->content;
		second = (current->next)->content;
		if (first->distance >= second->distance)
			current = current->next;
		else
		{
			temp = current->content;
			current->content = (current->next)->content;
			(current->next)->content = temp;
			current = origin;
		}
	}
}

void		render_sprite(t_map *map, int (*pixel_array)[map->resolution.x_res][1], float zbuffer[map->resolution.x_res])
{
	int			i;
	int			y;
	int 		x;
	int			d;
	float		sprite_x;
	float		sprite_y;
	float		inv_det;
	float		trans_x;
	float		trans_y;
	int			sprite_height;
	int			sprite_width;
	int			sprite_tex_x;
	int			draw_start_x;
	int			draw_start_y;
	int			draw_end_x;
	int			draw_end_y;
	int			tex_x;
	int			tex_y;
	t_sprite	*sprite;
	t_list		*lst;

	i = 0;
	lst = *map->sprite;
	while (i < map->plan.sprite_nb)
	{
		sprite = (t_sprite *)lst->content;
		sprite_x = (float)sprite->x - map->camera.pos_x;
		sprite_y = (float)sprite->y - map->camera.pos_y;

		inv_det = 1.0 / (map->camera.plan_x * map->camera.dir_y - map->camera.dir_x * map->camera.plan_y);

		trans_x = inv_det * (map->camera.dir_y * sprite_x - map->camera.dir_x * sprite_y);
		trans_y = inv_det * (-map->camera.plan_y * sprite_x - map->camera.plan_x * sprite_y);

		sprite_tex_x = (int)(((float)map->resolution.x_res / 2.0) * (1.0 + trans_x / trans_y));

		sprite_height = abs((int)((float)map->resolution.y_res / trans_y));
		if ((draw_start_y = -sprite_height / 2 + map->resolution.y_res / 2) < 0)
			draw_start_y = 0;
		if ((draw_end_y = sprite_height / 2 + map->resolution.x_res / 2) >= map->resolution.y_res)
			draw_end_y = map->resolution.y_res - 1;

		sprite_width = abs((int)((float)map->resolution.y_res / trans_y));
		draw_start_x = -sprite_width / 2 + sprite_tex_x;
		if (draw_start_x < 0)
			draw_start_x = 0;
		draw_end_x = sprite_width / 2 + sprite_tex_x;
		if (draw_end_x >= map->resolution.x_res)
			draw_end_x = map->resolution.x_res - 1;

		x = draw_start_x;
		while (x < draw_end_x)
		{
			tex_x = (int)((256 * (draw_start_x - (-sprite_width / 2 + sprite_tex_x)) * map->texture.s.w / sprite_width) / 256);
			if (trans_y > 0 && x > 0 && x < map->resolution.x_res && trans_y < zbuffer[x])
			{
				y = draw_start_y;
				while (y < draw_end_y)
				{
					d = y * 256 - map->resolution.y_res * 128 + sprite_height * 128;
					tex_y = ((d * map->texture.s.h) / sprite_height) / 256;
					*pixel_array[y][x] = map->texture.s.mapping[(tex_y * map->texture.s.w) + tex_x];
					y++;
				}
			}
			x++;
		}
		i++;
		lst = lst->next;
	}
}
