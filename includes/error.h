/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomasgermain <thomasgermain@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 09:27:17 by thomasgerma       #+#    #+#             */
/*   Updated: 2020/01/10 09:49:14 by thomasgerma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

/* line %d, column %d, char %c*/
# define ERR_WRG_PAR "Error\nWrong parameter in map: (line %d: column %d: char '%c')\n"
/* line %d, column %d, char %c*/
# define ERR_WRG_OUTLINE "Error\nBad outline in map: (line %d: column %d: char '%c')\n"
/* column %d, char %c*/
# define ERR_WRG_LST_LINE "Error\nBad outline in map: (last line: column %d: char '%c')\n"

#endif
