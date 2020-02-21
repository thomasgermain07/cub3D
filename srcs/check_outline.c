/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_outline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 16:26:37 by thgermai          #+#    #+#             */
/*   Updated: 2020/02/21 16:39:51 by thgermai         ###   ########.fr       */
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

void		ask_for_perm(t_map *map)
{
	char	*answer;
	int		i;
	int		j;

	printf("\nDo you want to correct the map : 'yes' or 'no'\n");
	get_next_line(0, &answer);
	ft_add_ptr(answer, map->ptr_lst, &free);
	if ((i = -1) && !ft_strncmp(answer, "yes", 3))
	{
		while (map->plan.plan[++i])
		{
			j = -1;
			while (map->plan.plan[i][++j])
				if (map->plan.plan[i][j] == 'X')
					map->plan.plan[i][j] = '1';
		}
		ft_printf("Map changed\n");
	}
	else if (!ft_strncmp(answer, "no", 2))
		exit_prog(map);
	else
	{
		ft_printf("'yes' or 'no' only\n");
		ask_for_perm(map);
	}
}

void		check_outline(t_map *map, char **plan)
{
	int 	i;
	int 	j;
	int 	diff;
	int		error;

	error = check_first_line(plan[0]);
	i = 0;
	while (plan[++i])
	{
		j = ft_strlen(plan[i]) - 1;
		if (plan[i][0] != '1' || plan[i][j] != '1')
		{
			ft_printf(ERR_WRG_OUTLINE, map->plan.current_line, j, plan[i][j]);
			exit_prog(map);
		}
		diff = (ft_strlen(plan[i - 1]) - 1) - j;
		if (diff < 0)
		{
			while (diff)
			{
				if (plan[i][j + diff] != '1')
				{
					error = 1;
					plan[i][j + diff] = 'X';
				}
				diff++;
			}
		}
		else if (diff > 0)
		{
			while (diff)
			{
				if (plan[i - 1][j + diff] != '1')
				{
					error = 1;
					plan[i - 1][j + diff] = 'X';
				}
				diff--;
			}
		}
	}
	if (check_last_line(plan[i - 1]))
		error = 1;
	if (error)
	{
		ft_printf("Error\nMap has leaks\n\n");
		print_map(map);
		ask_for_perm(map);
	}
}
