/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:13:32 by thgermai          #+#    #+#             */
/*   Updated: 2020/02/18 15:36:22 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			main(int ac, char **av)
{
	t_map	*map;

	if (ac == 1)
	{
		ft_printf(ERR_NO_ARG);
		return (0);
	}
	if (!(map = get_map(av[1])))
		return (0);
	if (ac == 2)
		open_window(map);
	else if (ac == 3)
	{
		if (!ft_strncmp("--save", av[2], ft_strlen(av[2])))
			get_image(map);
		else
			ft_printf("Error\nOption %s unkown\n", av[2]);
	}
	return (0);
}
