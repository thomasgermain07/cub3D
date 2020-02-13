/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:13:32 by thgermai          #+#    #+#             */
/*   Updated: 2020/02/13 17:17:37 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		get_image(t_map *map)
{
	int fd;

	map->mlx_param.mlx = mlx_init();
	get_all_texture(map);
	raycasting(map);
	fd = open("image.bmp", O_RDWR | O_CREAT , 777); // 777 give full permission

	t_header	*header;

	if ((header = ft_calloc(sizeof(t_header), 1)))
		return (0);
	header->signature[0] = 'B';
	header->signature[1] = 'M';



	close(fd);
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
		get_image(map);
	return (0);
}

