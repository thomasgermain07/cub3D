/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 15:05:11 by thgermai          #+#    #+#             */
/*   Updated: 2020/02/19 19:02:17 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		check_resolution(t_map *map)
{
	int			error;

	error = 0;
	if (map->resolution.x_res <= 0 || map->resolution.y_res <= 0)
		error = 1;
	if (map->resolution.x_res > 2560)
		map->resolution.x_res = 2560;
	if (map->resolution.y_res > 1440)
		map->resolution.y_res = 1440;
	if (error && (map->resolution.x_res < 0 || map->resolution.y_res < 0))
	{
		ft_printf(ERR_NEG_RES, map->resolution.x_res, map->resolution.y_res);
		exit_prog(map);
	}
	else if (error)
	{
		ft_printf(ERR_RES, map->resolution.x_res, map->resolution.y_res);
		exit_prog(map);
	}
}

void		check_texture(t_map *map)
{
	if (!map->texture.ea.name)
	{
		ft_printf(ERR_TEXTURE, "EA");
		exit_prog(map);
	}
	else if (!map->texture.we.name)
	{
		ft_printf(ERR_TEXTURE, "WE");
		exit_prog(map);
	}
	else if (!map->texture.no.name)
	{
		ft_printf(ERR_TEXTURE, "NO");
		exit_prog(map);
	}
	else if (!map->texture.so.name)
	{
		ft_printf(ERR_TEXTURE, "SO");
		exit_prog(map);
	}
	else if (!map->texture.s.name)
	{
		ft_printf(ERR_TEXTURE, "S");
		exit_prog(map);
	}
}

void		check_player(t_map *map)
{
	if (!map->player.orientation)
	{
		ft_printf(ERR_PLAY_MISS);
		exit_prog(map);
	}
}

void		check_map(t_map *map)
{
	check_resolution(map);
	check_texture(map);
	check_player(map);
}
