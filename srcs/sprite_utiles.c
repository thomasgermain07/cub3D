/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utiles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 15:24:19 by thgermai          #+#    #+#             */
/*   Updated: 2020/02/11 13:19:31 by thgermai         ###   ########.fr       */
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

void		complete_sprite(t_map *map)
{
	t_list		*lst;
	t_sprite	*sprite;

	lst = *map->sprite;
	while (lst)
	{
		sprite = lst->content;
		if (sprite->x == map->camera.map_x + 0.5 &&
			sprite->y == map->camera.map_y + 0.5)
			sprite->visible = 1;
		lst = lst->next;
	}
}

void		register_sprite(t_map *map, int x, int y)
{
	t_sprite	*new_sprite;
	t_list		*new_elem;

	if (!(new_sprite = malloc(sizeof(t_sprite))))
		exit(0);
	new_sprite->x = (float)x + 0.5;
	new_sprite->y = (float)y + 0.5;
	new_sprite->visible = 0;
	new_elem = ft_lstnew(new_sprite);
	ft_lstadd_back(map->sprite, new_elem);
}

void	respaw_sprite(t_map *map)
{
	t_list 		*lst;
	t_sprite	*sprite;

	lst = *map->sprite;
	while (lst)
	{
		sprite = lst->content;
		map->plan.plan[(int)sprite->x][(int)sprite->y] = '2';
		lst = lst->next;
	}
	map->plan.sprite_collected = 0;
}

void	pick_up_sprite(t_map *map)
{
	map->plan.sprite_collected ++;
	map->plan.plan[(int)map->player.x][(int)map->player.y] = '0';
	// play sound;

}
