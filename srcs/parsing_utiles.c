/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utiles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 16:04:51 by thgermai          #+#    #+#             */
/*   Updated: 2020/02/23 16:05:40 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
