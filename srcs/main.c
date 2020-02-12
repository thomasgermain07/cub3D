/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:13:32 by thgermai          #+#    #+#             */
/*   Updated: 2020/02/12 16:39:39 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		get_image(t_map *map)
{
	map->mlx_param.mlx = mlx_init();
	get_all_texture(map);
	raycasting(map);
	int fd = open("image.bmp", O_CREAT | O_RDWR , 777); // 777 give full permission

	close(fd);
}

int			main(int ac, char **av)
{
	t_map	*map;

	if(ac == 1)
	{
		ft_printf("Error\nExpected at least 2 arguments\n");
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

