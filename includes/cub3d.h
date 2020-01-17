/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 08:24:46 by thgermai          #+#    #+#             */
/*   Updated: 2020/01/17 08:57:23 by thgermai         ###   ########.fr       */
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
	void	*mlx;
	void	*window;
	void	*image;
}					t_mlx_param;

typedef struct		s_map
{
	t_resolution	resolution;
	t_texture		texture;
	t_player		player;
	t_mlx_param		mlx_param;
	t_plan			plan;
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


void				raycasting(t_map *map);
#endif
