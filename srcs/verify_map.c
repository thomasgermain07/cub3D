/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 15:05:11 by thgermai          #+#    #+#             */
/*   Updated: 2020/02/23 17:42:54 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		correct_resolution(int *res)
{
	int		r;

	if (*res % 2)
		*res += 1;
	r = *res % 100;
	if (r == 14 || r == 50 || r == 70 || r == 90 || r == 26
		|| r == 66 || r == 86 || r == 6 || r == 30 || r == 18
		|| r == 38 || r == 78 || r == 98 || r == 58)
		*res += 2;
}

void		check_resolution(t_map *map)
{
	int			error;

	error = 0;
	if (map->resolution.x_res <= 0 || map->resolution.y_res <= 0)
		error = 1;
	correct_resolution(&map->resolution.x_res);
	correct_resolution(&map->resolution.y_res);
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

void		check_map(t_map *map)
{
	check_resolution(map);
	check_texture(map);
	if (!map->player.orientation)
	{
		ft_printf(ERR_PLAY_MISS);
		exit_prog(map);
	}
}
