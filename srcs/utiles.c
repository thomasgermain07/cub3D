/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:57:23 by thgermai          #+#    #+#             */
/*   Updated: 2020/02/24 11:13:25 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char		*skip_space(char *str)
{
	char		*temp;
	int			i;

	i = 0;
	if (!ft_strlen(str))
		return (NULL);
	while (str[i] == ' ')
		i++;
	temp = ft_strdup(str + i);
	return (temp);
}

void		exit_prog(t_map *map)
{
	if (*map->sprite)
		ft_lstclear(map->sprite, free);
	ft_free_ptrlst(map->ptr_lst);
	system("leaks cub3D");
	exit(0);
}

void		del_mlx_data(t_map *map, int option)
{
	if (map->texture.ea.image)
		mlx_destroy_image(map->mlx_param.mlx, map->texture.ea.image);
	if (map->texture.no.image)
		mlx_destroy_image(map->mlx_param.mlx, map->texture.no.image);
	if (map->texture.so.image)
		mlx_destroy_image(map->mlx_param.mlx, map->texture.so.image);
	if (map->texture.we.image)
		mlx_destroy_image(map->mlx_param.mlx, map->texture.we.image);
	if (map->texture.s.image)
		mlx_destroy_image(map->mlx_param.mlx, map->texture.s.image);
	if (map->mlx_param.window && option == 1)
	{
		mlx_clear_window(map->mlx_param.mlx, map->mlx_param.window);
		mlx_destroy_window(map->mlx_param.mlx, map->mlx_param.window);
	}
	if (map->mlx_param.image && option == 1)
		mlx_destroy_image(map->mlx_param.mlx, map->mlx_param.image);
}

void		print_map(t_map *map)
{
	int		i;

	i = -1;
	while (map->plan.plan[++i])
		ft_printf_e("[%i]\t-> %s\n", i, map->plan.plan[i]);
}
