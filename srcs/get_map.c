/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 21:13:57 by thgermai          #+#    #+#             */
/*   Updated: 2020/02/26 11:49:32 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		convert_lst_to_tab(t_map *map, t_list *lst)
{
	int		i;

	i = 0;
	if (!lst)
	{
		ft_printf_e(ERR_MAP_MISS);
		exit_prog(map);
	}
	if (!(map->plan.plan = ft_add_ptr(malloc(sizeof(char *) *
		(ft_lstsize(lst) + 1)), map->ptr_lst, &free)))
		exit_prog(map);
	while (lst)
	{
		map->plan.plan[i] = ft_add_ptr(ft_strdup(lst->content),
			map->ptr_lst, &free);
		check_spawn(lst->content, map, map->plan.current_line);
		map->plan.current_line++;
		lst = lst->next;
		i++;
	}
	map->plan.plan[i] = NULL;
	check_map(map);
	check_outline(map, map->plan.plan);
}

void		read_file(int fd, t_map *map)
{
	char	*temp;
	int		ret;
	t_list	**list;

	if (!(list = malloc(sizeof(t_list *) * 1)))
		exit_prog(map);
	*list = NULL;
	temp = NULL;
	while ((ret = get_next_line(fd, &temp)))
	{
		if (ret == -1)
			exit_prog(map);
		if (temp)
		{
			parsing(temp, map, list);
			free(temp);
		}
	}
	if (temp)
		free(temp);
	map->plan.current_line = 0;
	convert_lst_to_tab(map, *list);
	map->plan.current_line = 0;
	ft_lstclear(list, free);
	free(list);
}

int			get_map(char *file_name, t_map *map)
{
	int		fd;
	int		i;

	i = -1;
	if ((fd = open(file_name, O_RDONLY)) == -1)
	{
		ft_printf_e(ERR_MAP_NAME, file_name);
		return (0);
	}
	if (!(map->ptr_lst = malloc(sizeof(t_list *) * 1)))
		return (0);
	*map->ptr_lst = NULL;
	if (!(map->sprite = ft_add_ptr(malloc(sizeof(t_list *) * 1),
		map->ptr_lst, &free)))
		exit_prog(map);
	*map->sprite = NULL;
	read_file(fd, map);
	while (map->plan.plan[++i])
		check_sprite(map->plan.plan[i], map);
	map->plan.sprite_nb = ft_lstsize(*map->sprite);
	close(fd);
	return (1);
}
