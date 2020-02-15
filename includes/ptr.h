/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 16:45:32 by thgermai          #+#    #+#             */
/*   Updated: 2020/02/15 18:10:09 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BMP_IMAGE_H
# define BMP_IMAGE_H

typedef struct 		s_ptrlst
{
	void				*ptr;
	void				(*fptr)(void *);
}					t_ptrlst;

#endif
