/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 08:53:15 by thgermai          #+#    #+#             */
/*   Updated: 2020/01/29 13:36:42 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		get_texture_no(t_map *map)
{
	void	*image;
	int		x;
	int		y;
	int		bit_per_pixel;

	if (!(image = mlx_xpm_file_to_image(map->mlx_param.mlx,
		map->texture.no.image, &map->texture.no.w, &map->texture.no.h)))
	{
		ft_printf(ERR_TEXTURE_PATH, map->texture.no.image);
		exit(0);
	}
	map->texture.no.mapping = (int *)mlx_get_data_addr(image, &bit_per_pixel, &x, &y);
}

void		get_texture_so(t_map *map)
{
	void	*image;
	int		x;
	int		y;
	int		bit_per_pixel;

	if (!(image = mlx_xpm_file_to_image(map->mlx_param.mlx,
		map->texture.so.image, &map->texture.so.w, &map->texture.so.h)))
	{
		ft_printf(ERR_TEXTURE_PATH, map->texture.so.image);
		exit(0);
	}
	map->texture.so.mapping = (int *)mlx_get_data_addr(image, &bit_per_pixel, &x, &y);
}

void		get_texture_ea(t_map *map)
{
	void	*image;
	int		x;
	int		y;
	int		bit_per_pixel;

	if (!(image = mlx_xpm_file_to_image(map->mlx_param.mlx,
		map->texture.ea.image, &map->texture.ea.w, &map->texture.ea.h)))
	{
		ft_printf(ERR_TEXTURE_PATH, map->texture.ea.image);
		exit(0);
	}
	map->texture.ea.mapping = (int *)mlx_get_data_addr(image, &bit_per_pixel, &x, &y);
}

void		get_texture_we(t_map *map)
{
	void	*image;
	int		x;
	int		y;
	int		bit_per_pixel;

	if (!(image = mlx_xpm_file_to_image(map->mlx_param.mlx,
		map->texture.we.image, &map->texture.we.w, &map->texture.we.h)))
	{
		ft_printf(ERR_TEXTURE_PATH, map->texture.we.image);
		exit(0);
	}
	map->texture.we.mapping = (int *)mlx_get_data_addr(image, &bit_per_pixel, &x, &y);
}

void		get_texture_sprite(t_map *map)
{
	void	*image;
	int		x;
	int		y;
	int		bit_per_pixel;

	if (!(image = mlx_xpm_file_to_image(map->mlx_param.mlx, map->texture.s.image,
		&map->texture.s.w, &map->texture.s.h)))
	{
		ft_printf(ERR_TEXTURE_PATH, map->texture.s.image);
		exit(0);
	}
	map->texture.s.mapping = (int *)mlx_get_data_addr(image, &bit_per_pixel, &x, &y);
}

void		get_all_texture(t_map *map)
{
	get_texture_no(map);
	get_texture_so(map);
	get_texture_ea(map);
	get_texture_we(map);
	get_texture_sprite(map);
}
