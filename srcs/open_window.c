/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 11:29:27 by thgermai          #+#    #+#             */
/*   Updated: 2020/01/14 09:41:08 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub3d.h"

void		close_window(t_map *map)
{
	mlx_clear_window(map->mlx_param.mlx, map->mlx_param.window);
	mlx_destroy_image(map->mlx_param.mlx, map->mlx_param.window);
	exit(0);
}

void		create_image(t_map *map, int x , int y)
{
	int		i;
	int		j;

	i = 150;
	j = 150;
	map->mlx_param.image = mlx_xpm_file_to_image(map->mlx_param.mlx, map->texture.s , &i, &j);
	mlx_put_image_to_window(map->mlx_param.mlx, map->mlx_param.window,	map->mlx_param.image, x, y);
	ft_printf("i -> %d : j -> %d\n", i, j);
}

void		moving(int *x, int *y, int direction, t_map *map)
{
	if (direction == 2)
		*x += 30;
	else if (direction == 0)
		*x -= 30;
	else if (direction == 13)
		*y -= 30;
	else if (direction == 1)
		*y += 30;
	if (map->mlx_param.image)
		mlx_clear_window(map->mlx_param.mlx, map->mlx_param.window);
	create_image(map, *x, *y);
}



int			key_center(int key, t_map *map)
{
	static int x = 0;
	static int y = 0;

	ft_printf("key -> %i\n", key);

	if (key == 53)
		close_window(map);
	if (key == 0 || key == 1 || key == 2 || key == 13)
		moving(&x, &y, key, map);
	if (key == 14)
		create_image(map, x, y);
	ft_printf("x = %d : y = %d\n", x, y);
	return (0);
}

void		open_window(t_map *map)
{
	map->mlx_param.mlx = mlx_init();
	map->mlx_param.window = mlx_new_window(map->mlx_param.mlx, map->resolution.x_res,
		map->resolution.y_res, "Cub3d");
	mlx_key_hook(map->mlx_param.window, key_center, map);
	mlx_loop(map->mlx_param.mlx);
}
