/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:56:40 by thgermai          #+#    #+#             */
/*   Updated: 2020/02/17 14:18:47 by thgermai         ###   ########.fr       */
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

unsigned int	conv_color(char *str)
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
	r = (int)pow(256, 2) * r;
	g = 256 * g;
	free(str);
	return (r + g + b);
}

void			parsing(char *str, t_map *map, t_list **list)
{
	if (ft_strnstr(str, "NO", ft_strlen(str)))
		map->texture.no.image = ft_add_ptr(skip_space(str +
			ft_find_in(str, 'O') + 1), map->ptr_lst, &free);
	else if (ft_strnstr(str, "SO", ft_strlen(str)))
		map->texture.so.image = ft_add_ptr(skip_space(str +
			ft_find_in(str, 'O') + 1), map->ptr_lst, &free);
	else if (ft_strnstr(str, "WE", ft_strlen(str)))
		map->texture.we.image = ft_add_ptr(skip_space(str +
			 ft_find_in(str, 'E') + 1), map->ptr_lst, &free);
	else if (ft_strnstr(str, "EA", ft_strlen(str)))
		map->texture.ea.image = ft_add_ptr(skip_space(str +
			ft_find_in(str, 'A') + 1), map->ptr_lst, &free);
	else if (ft_strnstr(str, "S", ft_strlen(str)) && !map->texture.s.image)
		map->texture.s.image = ft_add_ptr(skip_space(str +
			ft_find_in(str, 'S') + 1), map->ptr_lst, &free);
	else if (ft_strnstr(str, "R", ft_strlen(str)))
		get_resolution(str, map);
	else if (ft_strnstr(str, "F", ft_strlen(str)))
		map->ground = conv_color(skip_space(str + ft_find_in(str, 'F') + 1));
	else if (ft_strnstr(str, "C", ft_strlen(str)))
		map->ceiling = conv_color(skip_space(str + ft_find_in(str, 'C') + 1));
	else if (ft_strlen(str))
		if (!get_plan(str, list))
			exit_prog(map);
}
