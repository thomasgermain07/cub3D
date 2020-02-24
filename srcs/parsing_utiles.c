/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utiles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 16:04:51 by thgermai          #+#    #+#             */
/*   Updated: 2020/02/24 11:12:57 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int				test_format(char *temp)
{
	int		i;
	int		coma;
	int		error;

	i = -1;
	error = 0;
	coma = 0;
	while (temp[++i])
	{
		if (temp[i] == ',')
			coma++;
		if (!ft_isdigit(temp[i]) && temp[i] != ',')
			error = 1;
		if (temp[i] == ',' && (!temp[i + 1] || !temp[i - 1]))
			error = 1;
		if (temp[i] == ',' && temp[i + 1] && temp[i - 1])
			if (!ft_isdigit(temp[i + 1]) || !ft_isdigit(temp[i - 1]))
				error = 1;
	}
	if (coma != 2)
		error = 1;
	return (error);
}

void			check_color_format(char *str, t_map *map)
{
	char	*temp;
	int		error;

	error = 0;
	if (!(temp = del_plan_space(str)))
	{
		ft_printf_e(ERR_COLOR_MISS);
		exit_prog(map);
	}
	if (test_format(temp))
		error = 1;
	free(temp);
	if (error)
	{
		ft_printf_e(ERR_COLOR_FORMAT);
		exit_prog(map);
	}
}

unsigned int	conv_color(char *str, t_map *map)
{
	int				i;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	check_color_format(str, map);
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
		ft_printf_e(ERR_COLOR_FORMAT);
		exit_prog(map);
	}
	r = (int)pow(256, 2) * r;
	g = 256 * g;
	return (r + g + b);
}

char			*del_plan_space(char *str)
{
	int		i;
	int		j;
	char	*temp;

	j = 0;
	i = -1;
	if (!ft_strlen(str))
		return (NULL);
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
	temp[j] = '\0';
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
