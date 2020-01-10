/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 09:27:17 by thomasgerma       #+#    #+#             */
/*   Updated: 2020/01/10 18:22:11 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

/* line %d, column %d, char %c */
# define ERR_WRG_PAR "Error\nWrong parameter in map: (line %d: column %d: char '%c')\n"
/* line %d, column %d, char %c */
# define ERR_WRG_OUTLINE "Error\nBad outline in map: (line %d: column %d: char '%c')\n"
/* column %d, char %c */
# define ERR_WRG_LST_LINE "Error\nBad outline in map: (last line: column %d: char '%c')\n"
/* line %d, column %d, char %c */
# define ERR_SPAWN_EXIST "Error\nSpawn already exist: (line %d: column %d: char %c)\n"
/* x %d, y %d */
# define ERR_NEG_RES "Error\nResolution has '-' value: (x %d: y %d)\n"
/* x %d, y %d */
# define ERR_RES "Error\nResolution invalid: (x %d: y %d)\n"
/* %s */
# define ERR_TEXTURE "Error\nTexture %s missing\n"
# define ERR_PLAY_MISS "Error\nPlayer is missing\n"
# define ERR_MAP_MISS "Error\nMap is missing in .cub file\n"
#endif