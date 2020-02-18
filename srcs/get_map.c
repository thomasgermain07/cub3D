/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 21:13:57 by thgermai          #+#    #+#             */
/*   Updated: 2020/02/18 15:38:33 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		convert_lst_to_tab(t_map *map, t_list *lst)
{
	int		i;

	i = 0;
	if (!lst)
	{
		ft_printf(ERR_MAP_MISS);
		exit_prog(map);
	}
	if (!(map->plan.plan = ft_add_ptr(malloc(sizeof(char *) *
		(ft_lstsize(lst) + 1)), map->ptr_lst, &free)))
		exit_prog(map);
	while (lst)
	{
		check_line(lst->content, map);
		map->plan.plan[i] = ft_add_ptr(ft_strdup(lst->content),
			map->ptr_lst, &free);
		lst = lst->next;
		i++;
	}
	if (!check_last_line(map->plan.plan[i - 1]))
		exit_prog(map);
	map->plan.plan[i] = NULL;
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
	convert_lst_to_tab(map, *list);
	ft_lstclear(list, free);
	free(list);
}

t_map		*get_map(char *file_name)
{
	int		fd;
	t_map	*map;

	if (!(map = ft_calloc(sizeof(t_map), 1)))
		return (NULL);
	if ((fd = open(file_name, O_RDONLY)) == -1)
	{
		ft_printf(ERR_MAP_NAME, file_name);
		free(map);
		return (NULL);
	}
	if (!(map->ptr_lst = malloc(sizeof(t_list *) * 1)))
		return (NULL);
	*map->ptr_lst = NULL;
	if (!(map->sprite = ft_add_ptr(malloc(sizeof(t_list *) * 1),
		map->ptr_lst, &free)))
		exit_prog(map);
	*map->sprite = NULL;
	read_file(fd, map);
	check_map(map);
	map->plan.sprite_nb = ft_lstsize(*map->sprite);
	close(fd);
	return (map);
}
