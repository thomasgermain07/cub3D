/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_outline_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 14:21:34 by thgermai          #+#    #+#             */
/*   Updated: 2020/02/23 16:08:05 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		correct_map(char **plan)
{
	int		i;
	int		j;

	i = -1;
	while (plan[++i])
	{
		j = -1;
		while (plan[i][++j])
			if (plan[i][j] == 'X')
				plan[i][j] = '1';
	}
	ft_printf("\nMap changed\n\n");
}

void		handle_map_error(t_map *map)
{
	ft_printf("Error\nMap has leaks\n");
	if (map->mlx_param.auto_correction)
		correct_map(map->plan.plan);
	else
	{
		print_map(map);
		ask_for_perm(map);
	}
}

void		ask_for_perm(t_map *map)
{
	char	*answer;

	ft_printf("\nDo you want to correct the map : 'yes' or 'no'\n");
	ft_printf("If you accept, the next maps will be automatically corrected\n");
	get_next_line(0, &answer);
	ft_add_ptr(answer, map->ptr_lst, &free);
	if (!ft_strncmp(answer, "yes", ft_strlen(answer)))
	{
		map->mlx_param.auto_correction = 1;
		correct_map(map->plan.plan);
	}
	else if (!ft_strncmp(answer, "no", ft_strlen(answer)))
		exit_prog(map);
	else
	{
		ft_printf("'yes' or 'no' only\n");
		ask_for_perm(map);
	}
}

void		mark_error(char **plan, int i, int j, int *error)
{
	plan[i][j] = 'X';
	*error = 1;
}
