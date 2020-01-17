/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 11:29:27 by thgermai          #+#    #+#             */
/*   Updated: 2020/01/17 08:57:30 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub3d.h"

void		close_window(t_map *map)
{
	mlx_clear_window(map->mlx_param.mlx, map->mlx_param.window);
	mlx_destroy_image(map->mlx_param.mlx, map->mlx_param.window);
	exit(0);
}
// float		vertical(t_map *map)
// {
// 	float		case_size;
// 	float		current;

// 	case_size = map->resolution.x_res / map->plan.size_x;
// 	current = case_size;
// 	while (current < map->player.x)
// 		current += case_size;
// 	return (map->player.x - current);
// }

// float		horizontal(t_map *map)
// {
// 	float		case_size;
// 	float		current;

// 	case_size = map->resolution.y_res / map->plan.size_y;
// 	current = map->resolution.y_res;
// 	while (current > map->player.y)
// 		current -= case_size;
// 	return (map->player.y - current)
// }

// void		moving(int *x, int *y, int direction, t_map *map)
// {
// 	if (direction == 2)

// 	else if (direction == 0)

// 	else if (direction == 13)

// 	else if (direction == 1)

// 	else if (direction == 123)

// 	else if (direction == 124)
// }

int			key_center(int key, t_map *map)
{
	ft_printf("\nkey -> %i\n", key);
	if (key == 13)
		raycasting(map);
	if (key == 53)
		close_window(map);
	if (key == 14)
		create_mapping(map);
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


