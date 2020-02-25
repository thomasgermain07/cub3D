/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:13:32 by thgermai          #+#    #+#             */
/*   Updated: 2020/02/25 15:10:59 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		check_flag(char *str)
{
	if (ft_strlen(str) != 6 || str[0] != '-' || str[1] != '-' ||
		str[2] != 's' || str[3] != 'a' || str[4] != 'v' || str[5] != 'e')
	{
		ft_printf_e(ERR_UNKNOW_OPTION, str);
		exit(0);
	}
}

void		check_extention(char *str)
{
	int		i;
	int		error;

	error = 0;
	i = ft_strlen(str) - 1;
	if (str[i] != 'b')
		error = 1;
	if (str[i - 1] != 'u')
		error = 1;
	if (str[i - 2] != 'c')
		error = 1;
	if (str[i - 3] != '.')
		error = 1;
	if (error)
	{
		ft_printf_e(ERR_WRONG_EXTENTION, str);
		exit(0);
	}
}

int			main(int ac, char **av)
{
	t_map	map;

	ft_bzero(&map, sizeof(t_map));
	map.ceiling = -1;
	map.ground = -1;
	if (ac == 1)
	{
		ft_printf_e(ERR_NO_ARG);
		return (0);
	}
	check_extention(av[1]);
	if (av[2])
		check_flag(av[2]);
	if (!get_map(av[1], &map))
		return (0);
	if (ac == 2)
		open_window(&map);
	else if (ac == 3)
		get_image(&map);
	return (0);
}
