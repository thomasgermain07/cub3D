/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 08:24:46 by thgermai          #+#    #+#             */
/*   Updated: 2020/01/20 14:22:05 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>
# include "error.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct		s_player
{
	int				x;
	int				y;
	char			orientation;
	int				dir_x;
	int				dir_y;
}					t_player;

typedef struct		s_resolution
{
	int 			x_res;
	int				y_res;
}					t_resolution;

typedef struct		s_plan
{
	int				size_x;
	int				size_y;
	char			**plan;
}					t_plan;


typedef struct		s_texture
{
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*s;
}					t_texture;

typedef struct		s_mlx_param
{
	void			*mlx;
	void			*window;
	int				*image;
}					t_mlx_param;

 typedef struct		s_camera
 {
	float			pos_x;
	float			pos_y;
	float			dir_x;
	float			dir_y;
	float			plan_x;
	float			plan_y;
	float			camera_x;
	float			ray_pos_x;
	float			ray_pos_y;
	float			ray_dir_x;
	float			ray_dir_y;
	int				map_x;
	int				map_y;
	float			side_dist_x;
	float			side_dist_y;
	float			delta_dist_x;
	float			delta_dist_y;
	float			step_x;
	float			step_y;
	int				hit;
	int				side;
	float			perp_wall_dist;
	int				hateur_de_ligne;
	int				draw_start;
	int				draw_end;
 }					t_camera;

typedef struct		s_map
{
	t_resolution	resolution;
	t_texture		texture;
	t_player		player;
	t_mlx_param		mlx_param;
	t_plan			plan;
	t_camera		camera;
	int				ground;
	int				ceiling;
}					t_map;

char				*skip_space(char *str);
void				check_line(char *line, t_map *map);
void				check_last_line(char *line);
void				print_map(t_map *map);
void				parsing(char *str, t_map *map, t_list **list);
void				get_plan(char *str, t_list **list);
t_map				*get_map(char *file_name);
void				check_map(t_map *map);
void				open_window(t_map *map);
unsigned int		get_color(char *str);
void				create_mapping(t_map *map);
void				create_h_line(t_map *map);
void				create_v_line(float x, t_map *map);

int					(*get_img_addr(t_map *map))[][1];
void				raycasting(t_map *map);
#endif
