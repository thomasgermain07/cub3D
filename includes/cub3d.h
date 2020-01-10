/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomasgermain <thomasgermain@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 08:24:46 by thgermai          #+#    #+#             */
/*   Updated: 2020/01/10 09:40:43 by thomasgerma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "error.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct		s_resolution
{
	int 			x_res;
	int				y_res;
}					t_resolution;

typedef struct		s_texture
{
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*s;
}					t_texture;

typedef struct		s_map
{
	t_resolution	resolution;
	t_texture		texture;
	char			*ground;
	char			*ceiling;
	char			**plan;
}					t_map;

char				*skip_space(char *str);
void				check_outline(char *line);
void				check_last_line(char *line);
void				print_map(t_map *map);
void				parsing(char *str, t_map *map, t_list **list);
void				get_plan(char *str, t_list **list);
t_map				*get_map(char *file_name);


#endif
