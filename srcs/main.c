/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:13:32 by thgermai          #+#    #+#             */
/*   Updated: 2020/02/24 13:31:12 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
	if (!get_map(av[1], &map))
		return (0);
	if (ac == 2)
		open_window(&map);
	else if (ac == 3)
	{
		if (!ft_strncmp("--save", av[2], ft_strlen(av[2])))
			get_image(&map);
		else
			ft_printf_e("Error\nOption %s unkown\n", av[2]);
	}
	return (0);
}
