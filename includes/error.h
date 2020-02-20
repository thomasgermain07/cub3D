/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 09:27:17 by thomasgerma       #+#    #+#             */
/*   Updated: 2020/02/20 16:26:05 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

/*
** line %d, column %d, char %c
*/
# define ERR_WRG_PAR "Error\nWrong parameter in map: (l %d: c %d: '%c')\n"
/*
** line %d, column %d, char %c
*/
# define ERR_WRG_OUTLINE "Error\nBad outline in map: (l %d: c %d: '%c')\n"
/*
**  column %d, char %c
*/
# define ERR_WRG_LST_LINE "Error\nBad outline in map: (last line: c %d: '%c')\n"
/*
** line %d, column %d, char %c
*/
# define ERR_SPAWN_EXIST "Error\nSpawn already exist: (l %d: c %d: %c)\n"
/*
** x %d, y %d
*/
# define ERR_NEG_RES "Error\nResolution has '-' value: (x %d: y %d)\n"
/*
** x %d, y %d
*/
# define ERR_RES "Error\nResolution invalid: (x %d: y %d)\n"
/*
** %s
*/
# define ERR_TEXTURE "Error\nTexture %s missing\n"
# define ERR_PLAY_MISS "Error\nPlayer is missing\n"
# define ERR_MAP_MISS "Error\nMap is missing in .cub file\n"
/*
** %s
*/
# define ERR_TEXTURE_PATH "Error\nFile \"%s\" not found\n"
# define ERR_NO_ARG "Error\nExpected at least 2 arguments\n"
# define ERR_CRT_IMG "Error\nFailed to create image\n"
# define ERR_MAP_NAME "Error\n%s does not exist\n"
# define ERR_COLOR "Error\nColor unvalid in .cub\n"
# define ERR_PAR_AFTER_MAP "Error\nParameter after definition of the map\n"

#endif
