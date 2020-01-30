/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 15:24:19 by thgermai          #+#    #+#             */
/*   Updated: 2020/01/30 15:38:39 by thgermai         ###   ########.fr       */
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
