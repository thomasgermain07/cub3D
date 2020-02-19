/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:56:40 by thgermai          #+#    #+#             */
/*   Updated: 2020/02/19 18:38:27 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			get_resolution(char *str, t_map *map)
{
	int		i;
	char	*temp;

	i = ft_find_in(str, 'R');
	temp = skip_space(str + i + 1);
	free(str);
	map->resolution.x_res = ft_atoi(temp);
	i = 0;
	while (ft_isalnum(temp[i]))
		i++;
	str = skip_space(temp + i);
	free(temp);
	map->resolution.y_res = ft_atoi(str);
}

char			*del_plan_space(char *str)
{
	int		i;
	int		j;
	char	*temp;

	j = 0;
	i = -1;
	while (str[++i])
		if (str[i] == ' ')
			j++;
	if (!(temp = ft_calloc(sizeof(char), i - j + 1)))
		return (NULL);
	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] != ' ')
		{
			temp[j] = str[i];
			j++;
		}
	}
	return (temp);
}

int				get_plan(char *str, t_list **list)
{
	t_list	*new_elem;
	char	*temp;

	if (!(temp = del_plan_space(str)))
		return (0);
	new_elem = ft_lstnew(temp);
	ft_lstadd_back(list, new_elem);
	return (1);
}

unsigned int	conv_color(char *str, t_map *map)
{
	int				i;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	i = 0;
	r = ft_atoi(str);
	while (ft_isdigit(str[i]) || str[i] == ' ')
		i++;
	g = ft_atoi(str + i + 1);
	i++;
	while (ft_isdigit(str[i]) || str[i] == ' ')
		i++;
	b = ft_atoi(str + i + 1);
	if (r > 255 || g > 255 || b > 255 || r < 0 || g < 0 || b < 0)
	{
		ft_printf(ERR_COLOR);
		exit_prog(map);
	}
	r = (int)pow(256, 2) * r;
	g = 256 * g;
	return (r + g + b);
}

void			register_texture(t_map *map, t_image *texture, char *str)
{
	char		*temp;

	temp = skip_space(str);
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
	else if (str[0] == 'S' && str[1] == ' ')
		register_texture(map, &map->texture.s, str +  1);
	else if (str[0] == 'F' && str[1] == ' ')
		map->ground = conv_color(str + 1, map);
	else if (str[0] == 'C' && str[1] == ' ')
		map->ceiling = conv_color(str + 1, map);
	else if (str[0] == 'R' && str[1] == ' ')
		get_resolution(str, map);
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
		if (ft_find_in("012NSEW", str[i]) == -1)
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
}
