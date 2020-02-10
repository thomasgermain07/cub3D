/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 08:24:46 by thgermai          #+#    #+#             */
/*   Updated: 2020/02/10 16:38:46 by thgermai         ###   ########.fr       */
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

# define MV_SPEED 0.065
# define ROT_SPEED 0.045

typedef struct		s_movement
{
	int				foward;
	int				backward;
	int				left;
	int				right;
	int				turn_left;
	int				turn_right;
	float			mv_speed;
	float			rot_speed;
	float			former_mv_speed;
	float			former_rot_speed;
}					t_movement;

typedef struct		s_sprite
{
	float			x;
	float			y;
	float			distance;
	int				visible;
	float			sprite_x;
	float			sprite_y;
	float			inv_det;
	float			trans_x;
	float			trans_y;
	int				screen_x;
	int				height;
	int				width;
	int				draw_start_x;
	int				draw_start_y;
	int				draw_end_x;
	int				draw_end_y;
	float			tex_x;
	float			tex_y;
	float			wall_x;
	int				stripe;
	int				pix;
	unsigned int	color;
}					t_sprite;

typedef struct		s_player
{
	float			x;
	float			y;
	char			orientation;
	float			dir_x;
	float			dir_y;
	t_movement		movement;
}					t_player;

typedef struct		s_resolution
{
	int				x_res;
	int				y_res;
}					t_resolution;

typedef struct		s_plan
{
	int				size_x;
	int				size_y;
	char			**plan;
	int				sprite_nb;
	int				sprite_collected;
}					t_plan;

typedef struct		s_image
{
	char			*image;
	int				*mapping;
	int				h;
	int				w;
}					t_image;

typedef struct		s_texture
{
	t_image			no;
	t_image			so;
	t_image			we;
	t_image			ea;
	t_image			s;
}					t_texture;

typedef struct		s_mlx_param
{
	void			*mlx;
	void			*window;
	int				*image;
	char			*mapping;
}					t_mlx_param;

typedef struct		s_camera
{
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
	int				hauteur_ligne;
	int				draw_start;
	int				draw_end;
	float			wall_x;
	unsigned int	color;
	float			tex_x;
	float			tex_y;
}					t_camera;

typedef struct		s_map
{
	t_resolution	resolution;
	t_texture		texture;
	t_player		player;
	t_mlx_param		mlx_param;
	t_plan			plan;
	t_camera		camera;
	t_list			**sprite;
	int				ground;
	int				ceiling;
}					t_map;
/*
** ---- Parsing part ----
*/
char				*skip_space(char *str);
void				check_line(char *line, t_map *map);
void				check_last_line(char *line);
void				print_map(t_map *map);
void				parsing(char *str, t_map *map, t_list **list);
void				get_plan(char *str, t_list **list);
t_map				*get_map(char *file_name);
void				check_map(t_map *map);
void				open_window(t_map *map);
unsigned int		conv_color(char *str);
void				get_all_texture(t_map *map);
/*
** ----- Raycasting algo ----
*/
void				set_up_camera(t_map *map);
void				initiate_algo_value(t_map *map, int x);
void				get_ray_dir(t_map *map);
void				check_for_hit(t_map *map);
void				prepare_for_printing(t_map *map);
void				raycasting(t_map *map);
void				prepare_the_texture(t_map *map);
void				get_the_color(t_map *map);
void				map_render(t_map *map, float buffer[map->resolution.x_res],
	int x);
void				create_background(t_map *map, int x);
/*
** ----- Moving gestion -----
*/
void				move_foward(t_map *map);
void				move_backward(t_map *map);
void				move_left(t_map *map);
void				move_right(t_map *map);
void				turn_right(t_map *map);
void				turn_left(t_map *map);
/*
** ----- Sprite handling -----
*/
void				calcul_sprite_dist(t_map *map);
void				sort_sprite(t_map *map);
void				complete_sprite(t_map *map);
void				get_sprite_color(t_map *map, t_image *texture, t_sprite *sprite);
void				register_sprite(t_map *map, int x, int y);
int					close_window(t_map *map);
void				sprite_render(t_map *map, float buffer[map->resolution.x_res]);
void				ft_put_pixel(t_map *map, int x, int y, unsigned int color);

#endif

/*
** system("afplay ./path_to_sound&") -> only mp3 et & important !
** system("pkill afplay") -> stop le sound
*/
