/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:13:32 by thgermai          #+#    #+#             */
/*   Updated: 2020/02/03 15:21:35 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			main(int ac, char **av)
{
	t_map	*map;

	(void)av;
	if (ac != 2)
		return (0);
	if (!(map = get_map(av[1])))
		return (0);
	open_window(map);
	//system("leaks cub3d");
	return (0);
}

/*
**	KEY_MEMO
** 53	= ESC
** 0	= Q
** 1	= S
** 2	= D
** 13	= Z
*/
