/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 11:29:27 by thgermai          #+#    #+#             */
/*   Updated: 2020/01/15 20:14:36 by thgermai         ###   ########.fr       */
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

void		raycasting(t_map *map)
{
	float	pos_x;
	float	pos_y;

	float	plan_x;
	float	plan_y;
	// balayage de bande de pixel
	int 	x;

	float cam_x;
	// point d'origine ray
	float ray_pos_x;
	float ray_pos_y;
	// direction ray depuis point d'origine
	float ray_dir_x;
	float ray_dir_y;

	plan_x = 0;
	plan_y = 0;

	pos_x = map->resolution.x_res / 2;
	pos_y = map->resolution.y_res / 2;
	// rendre perpendiculaire la vue et le plan de projection
	if (map->player.orientation == 'N' || map->player.orientation == 'S')
		plan_y = 1;
	else if (map->player.orientation == 'W' || map->player.orientation == 'E')
		plan_x = 1;

	x = 0;

	cam_x = (2 * x / map->resolution.x_res) - 1;

	ray_pos_x = pos_x;
	ray_pos_y = pos_y;

	ray_dir_x = map->player.dir_x + (plan_x * cam_x);
	ray_dir_y = map->player.dir_y + (plan_y * cam_x);

	printf("x = %d\npos_x %f : pos_y %f\ncam_x %f\nray_pos_x %f: ray_pos_y %f\nray_dir_x %f : ray_dir_y %f\n\n", x, pos_x, pos_y, ray_pos_x, ray_pos_y,cam_x, ray_dir_x, ray_dir_y);

	// float	side_dist_x;
	// float	side_dist_y;

	float	delta_dist_x;
	float	delta_dist_y;

	delta_dist_x = sqrt(1 + (ray_dir_y * ray_dir_y) / (ray_dir_x * ray_dir_x));
	delta_dist_y = sqrt(1 + (ray_dir_x * ray_dir_x) / (ray_dir_y * ray_dir_y));

	printf("delta_dist_x %f : delta_dist_y %f\n", delta_dist_x, delta_dist_y);
}

int			key_center(int key, t_map *map)
{
	ft_printf("\nkey -> %i\n", key);
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


