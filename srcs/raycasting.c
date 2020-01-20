/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 08:56:48 by thgermai          #+#    #+#             */
/*   Updated: 2020/01/20 11:21:25 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		create_background(t_map *map, int size, int (*pixel_array)[size][1])
{
	int i;
	int j;

	i = 0;
	while (i < map->resolution.y_res / 2)
	{
		j = 0;
		while (j < map->resolution.x_res)
			*pixel_array[i][j++] = map->ceiling;
		i++;
	}
	while (i < map->resolution.y_res)
	{
		j = 0;
		while (j < map->resolution.x_res)
			*pixel_array[i][j++] = map->ground;
		i++;
	}
}

void		raycasting(t_map *map)
{
	float	pos_x = map->player.x; // Position de la camera -> Depart des rayons donc le centre de l'ecran
	float	pos_y = map->player.y;
	float	dir_x = (float)map->player.dir_x; // Direction de la camera
	float	dir_y = (float)map->player.dir_y;
	float	plan_x = 0; // Direction du plan -> Doit etre perpandiculaire a la direction de la camera
	float	plan_y = 0;
	int		x = 0;
	float	camera_x;
	float	ray_pos_x;
	float	ray_pos_y;
	float	ray_dir_x;
	float	ray_dir_y;
	int		map_x;
	int		map_y;
	float	side_dist_x;
	float	side_dist_y;
	float	delta_dist_x;
	float	delta_dist_y;
	float	step_x;
	float	step_y;
	int		hit; // Savoir si on touche un mur ou pas
	int		side; // Savoir quelle face on touche
	float	perp_wall_dist; // Distance corriger du rayon
	int		hauteur_ligne;
	int		draw_start;
	int		draw_end;
	int		color;
	int		(*pixel_array)[map->resolution.x_res][1] = get_img_addr(map);

	create_background(map, map->resolution.x_res, pixel_array);
	if (dir_x == -1.0)
		plan_y = 1.0;
	else if (dir_y == -1.0)
		plan_x = 1.0;
	else if (dir_x == 1.0)
		plan_y = -1.0;
	else if (dir_y == 1.0)
		plan_x = -1.0;
	while (x <= map->resolution.x_res)
	{
		camera_x = (2.0 * (float)x / (float)map->resolution.x_res) - 1.0;
		ray_pos_x = pos_x;
		ray_pos_y = pos_y;
		ray_dir_x = dir_x + plan_x * camera_x;
		ray_dir_y = dir_y + plan_y * camera_x;
		map_x = (int)ray_pos_x; // Position du joueur sur la map
		map_y = (int)ray_pos_y;
		delta_dist_x = sqrt(1.0 + (ray_dir_y * ray_dir_y) / (ray_dir_x * ray_dir_x)); // Longueurs des rayons
		delta_dist_y = sqrt(1.0 + (ray_dir_x * ray_dir_x) / (ray_dir_y * ray_dir_y));
		if (ray_dir_x < 0)
		{
			step_x = -1.0;
			side_dist_x = (ray_pos_x - map_x) * delta_dist_x;
		}
		else
		{
			step_x = 1.0;
			side_dist_x = (map_x + 1 - ray_pos_x) * delta_dist_x;
		}
		if (ray_dir_y < 0)
		{
			step_y = -1.0;
			side_dist_y = (ray_pos_y - map_y) * delta_dist_y;
		}
		else
		{
			step_y = 1.0;
			side_dist_y = (map_y + 1 - ray_pos_y) * delta_dist_y;
		}
		hit = 0;
		while (!hit)
		{
			if (side_dist_x < side_dist_y)
			{
				side_dist_x += delta_dist_x; // Agrandis les rayons
				map_x += step_x;
				side = 0;
			}
			else
			{
				side_dist_y += delta_dist_y;
				map_y += step_y;
				side = 1;
			}
			if (map->plan.plan[map_x][map_y] == '1' || map->plan.plan[map_x][map_y] == '2')
				hit = 1;
		}
		if (!side)
			perp_wall_dist = fabs(((float)map_x - ray_pos_x + (1.0 - step_x) / 2.0) / ray_dir_x);
		else
			perp_wall_dist = fabs(((float)map_y - ray_pos_y + (1.0 - step_y) / 2.0) / ray_dir_y);
		hauteur_ligne = (int)fabs(map->resolution.y_res / perp_wall_dist);
		draw_start = -hauteur_ligne / 2 + map->resolution.y_res / 2;
		draw_end = hauteur_ligne / 2 + map->resolution.y_res / 2;
		if (draw_start < 0)
			draw_start = 0;
		if (draw_end >= map->resolution.y_res)
			draw_end = map->resolution.y_res - 1;
		color = 16443110;
		if (side == 1)
			color = 11119017;
		while (draw_start < draw_end)
		{
			*pixel_array[draw_start][x] = color;
			draw_start++;
		}
		x++;
	}
	mlx_put_image_to_window(map->mlx_param.mlx, map->mlx_param.window, map->mlx_param.image, 0, 0);
}
