/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:13:32 by thgermai          #+#    #+#             */
/*   Updated: 2020/02/14 16:49:39 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		get_image(t_map *map)
{
	int fd;
	map->mlx_param.mlx = mlx_init();
	get_all_texture(map);
	raycasting(map);

	fd = open("image.bmp", O_RDWR | O_CREAT , S_IRWXU);

	unsigned char	file_header[14];
	ft_memset(&file_header, 0, 14);
	file_header[0] = 'B';
	file_header[1] = 'M';
	file_header[10] = 54;

	unsigned char	image_header[40];
	ft_memset(&image_header, 0, 40);

	image_header[0] = 40;


	close(fd);
	return (1);
}

int			main(int ac, char **av)
{
	t_map	*map;

	if(ac == 1)
	{
		ft_printf(ERR_NO_ARG);
		return (0);
	}
	if (!(map = get_map(av[1])))
		return (0);
	if (ac == 2)
		open_window(map);
	else if (ac == 3)
	{
		if (!ft_strncmp("--screen", av[2], ft_strlen(av[2])))
			get_image(map);
		else
			ft_printf("Error\nOption %s unkown\n", av[2]);
	}
	return (0);
}

