/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:57:23 by thgermai          #+#    #+#             */
/*   Updated: 2020/01/09 21:29:42 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	print_map(t_map *map)
{
	ft_printf("resolution.x_res = %i\n", map->resolution.x_res);
	ft_printf("resolution.y_res = %i\n", map->resolution.y_res);

	ft_printf("\n");

	ft_printf("texture.no = %s\n", map->texture.no);
	ft_printf("texture.so = %s\n", map->texture.so);
	ft_printf("texture.we = %s\n", map->texture.we);
	ft_printf("texture.ea = %s\n", map->texture.ea);
	ft_printf("texture.s : %s\n", map->texture.s);

	ft_printf("\n");

	ft_printf("ground : %s\n", map->ground);
	ft_printf("ceiling : %s\n", map->ceiling);

	ft_printf("\n");

	for (int i = 0; map->plan[i]; i++)
		ft_printf("plan[%i] :\t%s\n", i, map->plan[i]);
}

char		*skip_space(char *str)
{
	char		*temp;
	int			i;

	i = 0;
	while (str[i] == ' ')
		i++;
	temp = ft_strdup(str + i);
	return (ft_exit_ptr(temp, 0));
}
