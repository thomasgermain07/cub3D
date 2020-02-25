/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 09:27:17 by thomasgerma       #+#    #+#             */
/*   Updated: 2020/02/25 14:25:37 by thgermai         ###   ########.fr       */
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
** line %d, column %d, char %c
*/
# define ERR_SPAWN_EXIST "Error\nSpawn already exist: (l %d: c %d: %c)\n"
/*
** x %d, y %d
*/
# define ERR_NEG_RES "Error\nResolution has '-' value: (x %d: y %d)\n"
# define ERR_RES_ARG "Error\nWrong resolution format: X, Y [Int, Int]\n"
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
# define ERR_PAR_AFTER_MAP "Error\nParameter after definition of the map\n"
# define ERR_MAP_LEAKS "Error\nMaps has leaks\n"
# define ERR_DOUBLE_DEF "Error\nMultiple definition in .cub\n"
# define ERR_COLOR_FORMAT "Error\nWrong format for color R,G,B [0, 255]\n"
# define ERR_COLOR_MISS "Error\nColor is missing in .cub file\n"
# define ERR_SHORT_LINE "Error\nLine %i is too shot (minimun 3 char)\n"
# define MSG1 "\nDo you want to correct the map : 'yes' or 'no'\n"
# define MSG2 "If you accept, the next maps will be automatically corrected\n"
# define MSG3 "'yes' or 'no' only\n"
# define ERR_UNKNOW_PARAM "Error\nUnkown parameter '%s'\n"
# define ERR_PARAM_IN_MAP "Error\nParamater declarated inside the map\n"

#endif
