/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:56:40 by thgermai          #+#    #+#             */
/*   Updated: 2020/02/25 14:06:31 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			get_resolution(char *str, t_map *map)
{
	int		i;

	i = 0;
	if (map->resolution.y_res || map->resolution.x_res)
	{
		ft_printf_e(ERR_DOUBLE_DEF);
		exit_prog(map);
	}
	map->resolution.x_res = ft_atoi(str);
	while (str[i] && (str[i] == ' ' || str[i] == '-'))
		i++;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	map->resolution.y_res = ft_atoi(str + i);
	while (str[i] && (str[i] == ' ' || str[i] == '-'))
		i++;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (str[i])
	{
		ft_printf_e(ERR_RES_ARG);
		exit_prog(map);
	}
}

void			register_texture(t_map *map, t_image *texture, char *str)
{
	char		*temp;

	temp = skip_space(str);
	if (texture->name)
	{
		ft_printf_e(ERR_DOUBLE_DEF);
		exit_prog(map);
	}
	texture->name = ft_add_ptr(temp, map->ptr_lst, &free);
}

int				check_rest(t_map *map, char *str)
{
	if (str[0] == 'F')
	{
		if (map->ground != -1)
			return (-1);
		map->ground = conv_color(str + 1, map);
	}
	else if (str[0] == 'C')
	{
		if (map->ceiling != -1)
			return (-1);
		map->ceiling = conv_color(str + 1, map);
	}
	else if (str[0] == 'N' && str[1] == 'X')
	{
		if (map->next_map)
			return (-1);
		map->next_map = ft_add_ptr(skip_space(str + 2), map->ptr_lst, &free);
	}
	else
		return (0);
	return (1);
}

int				define_param(t_map *map, char *str)
{
	int ret;

	ret = 0;
	if (str[0] == 'N' && str[1] == 'O')
		register_texture(map, &map->texture.no, str + 2);
	else if (str[0] == 'S' && str[1] == 'O')
		register_texture(map, &map->texture.so, str + 2);
	else if (str[0] == 'W' && str[1] == 'E')
		register_texture(map, &map->texture.we, str + 2);
	else if (str[0] == 'E' && str[1] == 'A')
		register_texture(map, &map->texture.ea, str + 2);
	else if (str[0] == 'S' && (!str[1] || str[1] == ' '))
		register_texture(map, &map->texture.s, str + 1);
	else if (str[0] == 'R')
		get_resolution(str + 1, map);
	else
	{
		if ((ret = check_rest(map, str)) == -1)
		{
			ft_printf_e(ERR_DOUBLE_DEF);
			exit_prog(map);
		}
		return (ret);
	}
	return (1);
}

void			parsing(char *str, t_map *map, t_list **list)
{
	if (ft_strlen(str))
	{
		while (*str == ' ')
			str++;
		if (!*list && define_param(map, str))
			return ;
		else if (define_map(str, map))
		{
			if (!get_plan(str, list))
				exit_prog(map);
		}
		else
		{
			if (!*list)
				ft_printf_e(ERR_UNKNOW_PARAM, str);
			else
				ft_printf_e(ERR_PARAM_IN_MAP);
			exit_prog(map);
		}
	}
	else if (*list)
	{
		ft_printf_e(ERR_PAR_AFTER_MAP);
		exit_prog(map);
	}
}
