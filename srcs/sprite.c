/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 10:35:18 by thgermai          #+#    #+#             */
/*   Updated: 2020/02/18 17:38:45 by thgermai         ###   ########.fr       */
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
		x = powf(map->player.x - (float)sprite->x, 2.0);
		y = powf(map->player.y - (float)sprite->y, 2.0);
		sprite->distance = x + y;
		sprite->visible = 0;
		lst = lst->next;
	}
}

void	sort_sprite(t_map *map)
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

void	initiate_value(t_map *map, t_sprite *sprite)
{
	sprite->sprite_x = sprite->x - map->player.x;
	sprite->sprite_y = sprite->y - map->player.y;
	sprite->inv_det = 1.0 / (map->camera.plan_x * map->player.dir_y -
		map->player.dir_x * map->camera.plan_y);
	sprite->trans_x = sprite->inv_det * (map->player.dir_y *
		sprite->sprite_x - map->player.dir_x * sprite->sprite_y);
	sprite->trans_y = sprite->inv_det * (-map->camera.plan_y *
		sprite->sprite_x + map->camera.plan_x * sprite->sprite_y);
	sprite->screen_x = (map->resolution.x_res / 2) * (1.0 +
		sprite->trans_x / sprite->trans_y);
	sprite->height = (int)fabs(map->resolution.x_res / sprite->trans_y) / 1.8;
	if ((sprite->draw_start_y = -sprite->height / 2 +
		map->resolution.y_res / 2) < 0)
		sprite->draw_start_y = 0;
	if ((sprite->draw_end_y = sprite->height / 2 +
		map->resolution.y_res / 2) >= map->resolution.y_res)
		sprite->draw_end_y = map->resolution.y_res - 1;
	sprite->width = (int)fabs(map->resolution.x_res / sprite->trans_y) / 1.5;
	sprite->draw_start_x = -sprite->width / 2 + sprite->screen_x;
	sprite->draw_end_x = sprite->width / 2 + sprite->screen_x;
}

void	print_sprite(t_map *map, t_sprite *sprite,
	float buffer[map->resolution.x_res])
{
	sprite->stripe = sprite->draw_start_x - 1;
	while (++sprite->stripe < sprite->draw_end_x)
	{
		sprite->pix = sprite->draw_start_y - 1;
		if (sprite->stripe >= 0 && sprite->stripe < map->resolution.x_res
			&& sprite->trans_y < buffer[sprite->stripe])
		{
			while (++sprite->pix < sprite->draw_end_y)
			{
				if (sprite->pix >= 0 && sprite->pix <= map->resolution.y_res)
				{
					get_sprite_color(map, &map->texture.s, sprite);
					if (sprite->color != 0xff000000)
						ft_put_pixel(map, sprite->pix, sprite->stripe,
							sprite->color);
				}
			}
		}
	}
}

void	sprite_render(t_map *map, float buffer[map->resolution.x_res])
{
	t_list		*lst;
	t_sprite	*sprite;

	lst = *map->sprite;
	while (lst)
	{
		sprite = lst->content;
		if (sprite->visible)
		{
			initiate_value(map, sprite);
			print_sprite(map, sprite, buffer);
		}
		lst = lst->next;
	}
}
