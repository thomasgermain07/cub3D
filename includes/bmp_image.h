/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_image.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 16:45:32 by thgermai          #+#    #+#             */
/*   Updated: 2020/02/13 16:55:43 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BMP_IMAGE_H
# define BMP_IMAGE_H

typedef struct		s_header
{
	char			signature[2];
	int				file_size;
	int				reserved;
	int				offset;

}					t_header;

#endif
