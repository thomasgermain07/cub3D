/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomasgermain <thomasgermain@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 21:18:23 by thgermai          #+#    #+#             */
/*   Updated: 2020/01/10 10:01:50 by thomasgerma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		check_last_line(char *line)
{
	int				i;

	i = -1;
	while (line[++i])
	{
		if (line[i] != '1')
		{
			ft_printf(ERR_WRG_LST_LINE, i, line[i]);
			exit (0);
		}
	}
}

void		check_first_line(char *line)
{
	int		j;

	j = -1;
	while (line[++j])
		{
			if (line[j] != '1')
			{
				ft_printf(ERR_WRG_OUTLINE, 1, j, line[j]);
				exit (0);
			}
		}
}

void		check_spawn(char *line, int x)
{
	static int		spawn = 0;

	/* check si spawn : si oui error sinon stocker X Y et Oriantation*/
}

void		check_outline(char *line)
{
	static int		i = 0;
	int				j;

	j = -1;
	if (!i)
		check_first_line(line);
	while (line[++j])
	{
		if (ft_find_in("012NSEW", line[j]) == -1)
		{
			if (ft_find_in("NSEW", line[j]))
				check_spawn(line, i);
			ft_printf(ERR_WRG_PAR, i, j, line[j]);
			exit (0);
		}
	}
	if (line[0] != '1' || line[--j] != '1')
	{
		ft_printf(ERR_WRG_OUTLINE, i, j, line[j]);
		exit (0);
	}
	i++;
}
