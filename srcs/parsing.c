/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:56:40 by thgermai          #+#    #+#             */
/*   Updated: 2020/02/23 21:37:05 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			get_resolution(char *str, t_map *map)
{
	int		i;

	i = 0;
	map->resolution.x_res = ft_atoi(str);
	while (str[i] && str[i] == ' ')
		i++;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	map->resolution.y_res = ft_atoi(str + i);
	while (str[i] && str[i] == ' ')
		i++;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (str[i])
	{
		ft_printf(ERR_RES_ARG);
		exit_prog(map);
	}
}

void			register_texture(t_map *map, t_image *texture, char *str)
{
	char		*temp;

	temp = skip_space(str);
	if (texture->name)
	{
		ft_printf(ERR_DOUBLE_DEF);
		exit_prog(map);
	}
	texture->name = ft_add_ptr(temp, map->ptr_lst, &free);
}

int				define_param(t_map *map, char *str)
{
	if (str[0] == 'N' && str[1] == 'O')
		register_texture(map, &map->texture.no, str + 2);
	else if (str[0] == 'S' && str[1] == 'O')
		register_texture(map, &map->texture.so, str + 2);
	else if (str[0] == 'W' && str[1] == 'E')
		register_texture(map, &map->texture.we, str + 2);
	else if (str[0] == 'E' && str[1] == 'A')
		register_texture(map, &map->texture.ea, str + 2);
	else if (str[0] == 'S')
		register_texture(map, &map->texture.s, str + 1);
	else if (str[0] == 'F')
		map->ground = conv_color(str + 1, map);
	else if (str[0] == 'C')
		map->ceiling = conv_color(str + 1, map);
	else if (str[0] == 'R')
		get_resolution(str + 1, map);
	else if (str[0] == 'N' && str[1] == 'X')
		map->next_map = ft_add_ptr(skip_space(str + 2), map->ptr_lst, &free);
	else
		return (0);
	return (1);
}

int				define_map(char *str, t_map *map)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (ft_find_in("012NSEW ", str[i]) == -1)
		{
			ft_printf(ERR_WRG_PAR, map->plan.current_line, i, str[i]);
			exit_prog(map);
		}
	}
	map->plan.current_line++;
	return (1);
}

void			parsing(char *str, t_map *map, t_list **list)
{
	int		i;

	i = 0;
	if (ft_strlen(str))
	{
		while (str[i] == ' ')
			i++;
		if (define_param(map, str + i))
			return ;
		else if (define_map(str + i, map))
		{
			if (!get_plan(str + i, list))
				exit_prog(map);
		}
	}
	else if (*list)
	{
		ft_printf(ERR_PAR_AFTER_MAP);
		exit_prog(map);
	}
}
