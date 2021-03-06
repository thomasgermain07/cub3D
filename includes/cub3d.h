/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 08:24:46 by thgermai          #+#    #+#             */
/*   Updated: 2020/02/25 19:40:16 by thgermai         ###   ########.fr       */
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
	int				forward;
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

typedef struct		s_hud
{
	float			x;
	float			y;
	float			height;
	float			width;
	float			start_x;
	float			end_x;
	float			start_y;
	float			end_y;
}					t_hud;

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
	int				origin_x;
	int				origin_y;
	int				spawn;
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
	char			**plan;
	int				sprite_nb;
	int				sprite_collected;
	int				current_line;
}					t_plan;

typedef struct		s_image
{
	char			*name;
	void			*image;
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
	int				auto_correction;
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
	t_hud			hud;
	int				ground;
	int				ceiling;
	char			*next_map;
	t_list			**ptr_lst;
}					t_map;
/*
** ---- Parsing ----
*/
char				*skip_space(char *str);
void				check_sprite(char *line, t_map *map);
void				print_map(t_map *map);
void				check_spawn(char *line, t_map *map, int i);
void				parsing(char *str, t_map *map, t_list **list);
int					get_map(char *file_name, t_map *map);
void				check_map(t_map *map);
void				open_window(t_map *map);
void				get_all_texture(t_map *map);
unsigned int		conv_color(char *str, t_map *map);
void				check_outline(t_map *map, char **plan);
void				check_charset(t_map *map, char *line, int i);
int					get_plan(char *str, t_list **list);
char				*del_plan_space(char *str);
void				correct_map(char **plan);
void				ask_for_perm(t_map *map);
void				mark_error(char **plan, int i, int j, int *error);
void				handle_map_error(t_map *map);
int					define_map(char *str, t_map *map);
/*
** ----- Raycasting ----
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
** ----- Movement gestion -----
*/
void				move_foward(t_map *map);
void				move_backward(t_map *map);
void				move_left(t_map *map);
void				move_right(t_map *map);
void				turn_right(t_map *map);
void				turn_left(t_map *map);
/*
** ----- Sprite  -----
*/
void				calcul_sprite_dist(t_map *map);
void				sort_sprite(t_map *map);
void				complete_sprite(t_map *map);
void				get_sprite_color(t_map *map, t_image *texture,
	t_sprite *sprite);
void				register_sprite(t_map *map, int x, int y);
void				sprite_render(t_map *map,
	float buffer[map->resolution.x_res]);
void				pick_up_sprite(t_map *map);
void				respaw_sprite(t_map *map);
/*
** ----- Leaving prog -----
*/
void				del_mlx_data(t_map *map, int option);
int					close_window(t_map *map);
void				exit_prog(t_map *map);
void				change_map(t_map *map);
/*
** ----- Other -----
*/
void				ft_put_pixel(t_map *map, int x, int y, unsigned int color);
void				get_image(t_map *map);

#endif
