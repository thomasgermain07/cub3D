/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utiles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 15:24:19 by thgermai          #+#    #+#             */
/*   Updated: 2020/02/18 16:08:09 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	complete_sprite(t_map *map)
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

void	register_sprite(t_map *map, int x, int y)
{
	t_sprite	*new_sprite;
	t_list		*new_elem;

	if (!(new_sprite = malloc(sizeof(t_sprite))))
		exit_prog(map);
	new_sprite->x = (float)x + 0.5;
	new_sprite->y = (float)y + 0.5;
	new_sprite->visible = 0;
	new_elem = ft_lstnew(new_sprite);
	ft_lstadd_back(map->sprite, new_elem);
}

void	respaw_sprite(t_map *map)
{
	t_list		*lst;
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
	map->plan.sprite_collected++;
	map->plan.plan[(int)map->player.x][(int)map->player.y] = '0';
}

/*
** system("afplay ./path_to_sound&") -> only mp3 et & important !
** system("pkill afplay") -> stop le sound
*/
