/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 11:29:27 by thgermai          #+#    #+#             */
/*   Updated: 2020/01/14 11:15:20 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub3d.h"

void		close_window(t_map *map)
{
	mlx_clear_window(map->mlx_param.mlx, map->mlx_param.window);
	mlx_destroy_image(map->mlx_param.mlx, map->mlx_param.window);
	exit(0);
}

void		create_v_line(float x, t_map *map)
{
	int i;

	i = -1;
	while (++i < map->resolution.y_res)
		mlx_pixel_put(map->mlx_param.mlx, map->mlx_param.window, x, i, map->ceiling);
}

void		create_h_line(t_map *map)
{
	int				i;
	int				map_size;
	float			case_size;
	float			current;

	map_size = 0;
	while (map->plan[map_size])
		map_size++;
	case_size = (float)map->resolution.y_res / map_size;
	current = case_size;
	while (current < map->resolution.y_res)
	{
		i = -1;
		while (++i < map->resolution.x_res)
			mlx_pixel_put(map->mlx_param.mlx, map->mlx_param.window, i, current, map->ground);
		current += case_size;
	}
}

void		create_mapping(t_map *map)
{
	int				map_size;
	float			case_size;
	float			current;

	map_size = ft_strlen(map->plan[0]);
	case_size = (float)map->resolution.x_res / map_size;
	current = case_size;
	while (current < map->resolution.x_res)
	{
		printf("%f\n", current);
		create_v_line(current, map);
		current += case_size;
	}
	create_h_line(map);
}

void		create_player(t_map *map, int x, int y)
{
	int		i;
	int		j;

	i = 1;
	while (i < 15)
	{
		j = -1;
		while (++j < i)
			mlx_pixel_put(map->mlx_param.mlx, map->mlx_param.window, x - j, y - i, 1238946);
		i++;
	}
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
	mlx_clear_window(map->mlx_param.mlx, map->mlx_param.window);
	create_mapping(map);
	create_player(map, *x, *y);
}

int			key_center(int key, t_map *map)
{
	static int x = 250;
	static int y = 250;

	ft_printf("\nkey -> %i\n", key);
	if (key == 53)
		close_window(map);
	if (key == 13 || key == 0 || key == 1 || key == 2)
		moving(&x, &y, key, map);
	if (key == 14)
		create_mapping(map);
	if (key == 15)
		create_player(map, x, y);
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
