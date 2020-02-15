/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 15:44:31 by thgermai          #+#    #+#             */
/*   Updated: 2020/02/15 19:22:38 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int 	main(void)
{
	t_list		**lst;

	lst = malloc(sizeof(t_list *) * 1);
	*lst = NULL;

	char	*str;
	char	*str2;
	char	*str3;

	str = ft_add_ptr(ft_strdup("salut"), lst, &free);
	str2 = ft_add_ptr(ft_strdup("les"), lst, &free);
	str3 = ft_add_ptr(ft_strdup("gens"), lst, &free);

	char **tab;

	tab = ft_add_ptr(malloc(sizeof(char *) * 5), lst, free);

	tab[0] = ft_add_ptr(ft_strdup("J'aime pas ce que je vois la"), lst, free);
	tab[1] = ft_add_ptr(ft_strdup("fasfasfas"), lst, free);
	tab[2] = ft_add_ptr(ft_strdup("Jhgkhgkhgkgla"), lst, free);
	tab[3] = ft_add_ptr(ft_strdup("J'ytiytiyiyti"), lst, free);
	tab[4] = NULL;

	ft_print_add_lst(lst);
	printf("\n\n");
	ft_del_ptr(lst, str2);
	ft_del_ptr(lst, tab[3]);
	ft_print_add_lst(lst);
	printf("\n\n");

	ft_free_ptrlst(lst);

	str = NULL;
	str2 = NULL;
	str3 = NULL;
	lst = NULL;
	system("leaks a.out");
	return (0);
}

