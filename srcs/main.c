/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:13:32 by thgermai          #+#    #+#             */
/*   Updated: 2020/01/11 13:24:14 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			main(int ac, char **av)
{
	t_map	*map;

	if (ac != 2)
		return (0);
	if (!(map = get_map(av[1])))
		return (0);
	// print_map(map);
	open_window(map);
	// system("leaks cub3d");
	return (0);
}
