/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 10:20:16 by thgermai          #+#    #+#             */
/*   Updated: 2020/02/18 17:47:00 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	moving_bits(unsigned char *str, int value)
{
	str[0] = (unsigned char)(value);
	str[1] = (unsigned char)(value >> 8);
	str[2] = (unsigned char)(value >> 16);
	str[3] = (unsigned char)(value >> 24);
}

void	get_file_header(t_map *map, int fd)
{
	unsigned char		file_header[14];
	int					size;

	size = 3 * (map->resolution.x_res * map->resolution.y_res);
	ft_memset(&file_header, 0, 14);
	file_header[0] = 'B';
	file_header[1] = 'M';
	moving_bits(&file_header[2], size + 54);
	file_header[10] = 54;
	write(fd, file_header, 14);
}

void	get_image_header(t_map *map, int fd)
{
	unsigned char	image_header[40];

	ft_memset(&image_header, 0, 40);
	image_header[0] = 40;
	moving_bits(&image_header[4], map->resolution.x_res);
	moving_bits(&image_header[8], map->resolution.y_res);
	image_header[12] = 1;
	image_header[14] = 24;
	image_header[20] = 3 * (map->resolution.x_res * map->resolution.y_res);
	write(fd, image_header, 40);
}

void	get_image_mapping(t_map *map, int fd)
{
	int					j;
	int					i;
	int					color;
	int					(*array)[map->resolution.x_res][1];
	unsigned char		pad[3];

	array = (void *)map->mlx_param.mapping;
	ft_memset(&pad, 0, 3);
	j = map->resolution.y_res;
	while (--j >= 0)
	{
		i = -1;
		while (++i < map->resolution.x_res)
		{
			color = *array[j][i];
			write(fd, &color, 3);
		}
		i = -1;
		while (++i < (4 - (map->resolution.x_res * 3) % 4) % 4)
			write(fd, &pad, 3);
	}
}

void	get_image(t_map *map)
{
	int		fd;

	map->mlx_param.mlx = mlx_init();
	get_all_texture(map);
	raycasting(map);
	if ((fd = open("image.bmp", O_RDWR | O_CREAT, S_IRWXU)) == -1)
	{
		ft_printf(ERR_CRT_IMG);
		exit_prog(map);
	}
	get_file_header(map, fd);
	get_image_header(map, fd);
	get_image_mapping(map, fd);
	close_window(map);
	close(fd);
}
