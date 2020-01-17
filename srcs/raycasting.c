/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 08:56:48 by thgermai          #+#    #+#             */
/*   Updated: 2020/01/17 13:56:02 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		raycasting(t_map *map)
{
	// Position de la camera -> Depart des rayons donc le centre de l'ecran
	float pos_x = map->player.x;
	float pos_y = map->player.y;
	// Direction de la camera
	float dir_x = map->player.dir_x;
	float dir_y = map->player.dir_y;
	// Direction du plan -> Doit etre perpandiculaire a la direction de la camera
	float plan_x = 0;
	float plan_y = 0;
	if (dir_x)
		plan_y = 1;
	else if (dir_y)
		plan_x = 1;
	// x est la colonne de pixel actuel
	int x = 0;
	float camera_x;
	float ray_pos_x;
	float ray_pos_y;
	float ray_dir_x;
	float ray_dir_y;
	int	map_x;
	int map_y;
	float side_dist_x;
	float side_dist_y;
	float delta_dist_x;
	float delta_dist_y;
	float step_x;
	float step_y;
	int hit = 0; // Savoir si on touche un mur ou pas
	int side; // Savoir quelle face on touche
	float perp_wall_dist; // Distance corriger du rayon
	int hauteur_ligne;
	int draw_start;
	int draw_end;
	int color;
	ft_printf("Start the RayCasting algo... \n");
	while (x <= map->resolution.x_res)
	{
		camera_x = (2.0 * (float)x / (float)map->resolution.x_res) - 1.0;
		ray_pos_x = pos_x;
		ray_pos_y = pos_y;
		ray_dir_x = dir_x + plan_x * camera_x;
		ray_dir_y = dir_y + plan_y * camera_x;
		// position sur la map actuel
		map_x = (int)ray_pos_x;
		map_y = (int)ray_pos_y;
		// longueur des rayons
		delta_dist_x = sqrt(1.0 + (ray_dir_y * ray_dir_y) / (ray_dir_x * ray_dir_x));
		delta_dist_y = sqrt(1.0 + (ray_dir_x * ray_dir_x) / (ray_dir_y * ray_dir_y));
		// calcule le vecteur de direction et la longueur entre deux segments
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
				side_dist_x += delta_dist_x; // Agrandir le rayons
				map_x += step_x;
				side = 0;
			}
			else
			{
				side_dist_y += delta_dist_y;
				map_y += step_y;
				side = 1;
			}
			if (map->plan.plan[map_x][map_y] != '0')
				hit = 1;
		}
		printf("map_x = %d\nray_pos_x = %f\nstep_x = %f\nray_dir_x = %f\n", map_x, ray_pos_x, step_x, ray_dir_x);
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
		color = map->ceiling;
		if (side == 1)
			color = map->ground;
		while (draw_start < draw_end)
		{
			mlx_pixel_put(map->mlx_param.mlx, map->mlx_param.window, x, draw_start, color);
			draw_start++;
		}
		x++;
	}
}
