/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:57:23 by thgermai          #+#    #+#             */
/*   Updated: 2020/01/22 08:09:24 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	print_map(t_map *map)
{
	ft_printf("---------------- Map ----------------\n\n");
	ft_printf("resolution.x_res : %i\n", map->resolution.x_res);
	ft_printf("resolution.y_res : %i\n", map->resolution.y_res);

	ft_printf("\n");

	ft_printf("texture.no : %s\n", map->texture.no);
	ft_printf("texture.so : %s\n", map->texture.so);
	ft_printf("texture.we : %s\n", map->texture.we);
	ft_printf("texture.ea : %s\n", map->texture.ea);
	ft_printf("texture.s : %s\n", map->texture.s);

	ft_printf("\n");

	printf("player.dir_x : %f\n", map->player.dir_x);
	printf("player.dir_y : %f\n", map->player.dir_y);
	ft_printf("player.orientation : %c\n", map->player.orientation);
	printf("player.x : %f\n", map->player.x);
	printf("player.y : %f\n", map->player.y);

	ft_printf("\n");

	char *ground = ft_itoa_address(map->ground);
	char *ceiling = ft_itoa_address(map->ceiling);
	ft_printf("ground : %i -> %s\n", map->ground, ground);
	ft_printf("ceiling : %i -> %s\n", map->ceiling, ceiling);
	free(ground);
	free(ceiling);

	ft_printf("\n");

	ft_printf("plan.size_x = %d : plan.size_y = %d\n", map->plan.size_x, map->plan.size_y);
	for (int i = 0; map->plan.plan[i]; i++)
		ft_printf("plan[%i] :\t%s\n", i, map->plan.plan[i]);
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
