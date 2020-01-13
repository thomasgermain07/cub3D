/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 11:29:27 by thgermai          #+#    #+#             */
/*   Updated: 2020/01/13 09:47:26 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub3d.h"

void		close_window(t_map *map)
{
	mlx_clear_window(map->mlx_param.mlx, map->mlx_param.window);
	mlx_destroy_image(map->mlx_param.mlx, map->mlx_param.window);
	exit(0);
}

void		create_image(t_map *map)
{
	void *image;

	image = mlx_xpm_file_to_image(map->mlx_param.mlx, map->texture.s, (int *)150, (int *)150);
	mlx_put_image_to_window(map->mlx_param.mlx, map->mlx_param.window, image, 150, 150);
}

int			key_center(int key, t_map *map)
{
	ft_printf("key -> %i\n", key);
	if (key == 53)
		close_window(map);
	if (key == 0)
		create_image(map);
	return (0);
}

void		open_window(t_map *map)
{
	map->mlx_param.mlx = mlx_init();
	map->mlx_param.window = mlx_new_window(map->mlx_param.mlx, map->resolution.x_res,
		map->resolution.x_res, "Cub3d");

	mlx_key_hook(map->mlx_param.window, key_center, map);
	mlx_loop(map->mlx_param.mlx);
	ft_printf("test1\n");
}
