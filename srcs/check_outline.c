/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_outline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 16:26:37 by thgermai          #+#    #+#             */
/*   Updated: 2020/02/23 17:19:30 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			check_last_line(char *line)
{
	int		i;
	int		error;

	i = -1;
	error = 0;
	while (line[++i])
	{
		if (line[i] != '1')
		{
			line[i] = 'X';
			error = 1;
		}
	}
	return (error);
}

int			check_first_line(char *line)
{
	int		j;
	int		error;

	j = -1;
	error = 0;
	while (line[++j])
	{
		if (line[j] != '1')
		{
			line[j] = 'X';
			error = 1;
		}
	}
	return (error);
}

int			check_diff(char **plan, int i, int j, int diff)
{
	int error;

	error = 0;
	if (diff < 0 && (diff--))
	{
		while (++diff)
			if (plan[i][j + diff + 1] != '1')
				mark_error(plan, i, j + diff + 1, &error);
	}
	else if (diff > 0 && (diff++))
	{
		while (--diff)
			if (plan[i - 1][j + diff] != '1')
				mark_error(plan, i - 1, j + diff, &error);
	}
	return (error);
}

void		check_outline(t_map *map, char **plan)
{
	int		i;
	int		j;
	int		diff;
	int		error;

	error = check_first_line(plan[0]);
	i = 0;
	while (plan[++i])
	{
		j = ft_strlen(plan[i]) - 1;
		if (plan[i][0] != '1' || plan[i][j] != '1')
		{
			ft_printf(ERR_WRG_OUTLINE, i, j, plan[i][j]);
			exit_prog(map);
		}
		diff = (ft_strlen(plan[i - 1]) - 1) - j;
		if (check_diff(plan, i, j, diff))
			error = 1;
	}
	if (check_last_line(plan[i - 1]))
		error = 1;
	if (error)
		handle_map_error(map);
}
