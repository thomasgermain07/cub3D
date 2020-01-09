/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 21:13:57 by thgermai          #+#    #+#             */
/*   Updated: 2020/01/09 23:46:12 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		init_map(t_map *map)
{
	map->resolution.x_res = 0;
	map->resolution.y_res = 0;
	map->texture.no = NULL;
	map->texture.so = NULL;
	map->texture.we = NULL;
	map->texture.ea = NULL;
	map->texture.s = NULL;
	map->ceiling = NULL;
	map->ground = NULL;
	map->plan = NULL;
}

void		convert_lst_to_tab(t_map *map, t_list *lst)
{
	int		i;

	i = 0;
	if (!(map->plan = malloc(sizeof(char *) * (ft_lstsize(lst) + 1))))
		exit(0);
	while (lst)
	{
		check_outline(lst->content);
		map->plan[i] = ft_strdup(lst->content);
		lst = lst->next;
		i++;
	}
	check_last_line(map->plan[i - 1]);
	map->plan[i] = NULL;
}

void		read_file(int fd, t_map *map)
{
	char	*temp;
	int		ret;
	t_list	**list;

	if (!(list = malloc(sizeof(t_list *) * 1)))
		exit(0);
	*list = NULL;
	temp = NULL;
	while ((ret = get_next_line(fd, &temp)) != 0)
	{
		if (ret == -1)
			exit(0);
		parsing(temp, map, list);
		free(temp);
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
		return (NULL);
	init_map(map);
	read_file(fd, map);
	close(fd);
	return (map);
}
