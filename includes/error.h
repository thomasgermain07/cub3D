/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 09:27:17 by thomasgerma       #+#    #+#             */
/*   Updated: 2020/02/25 15:05:32 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define ERR_WRG_PAR "Error\nWrong parameter in map: (l %d: c %d: '%c')\n"
# define ERR_WRG_OUTLINE "Error\nBad outline in map: (l %d: c %d: '%c')\n"
# define ERR_SPAWN_EXIST "Error\nSpawn already exist: (l %d: c %d: %c)\n"
# define ERR_NEG_RES "Error\nResolution has '-' value: (x %d: y %d)\n"
# define ERR_RES_ARG "Error\nWrong resolution format: X, Y [Int, Int]\n"
# define ERR_RES "Error\nResolution is invalid: (x %d: y %d)\n"
# define ERR_TEXTURE "Error\nTexture %s is missing\n"
# define ERR_PLAY_MISS "Error\nPlayer is missing\n"
# define ERR_MAP_MISS "Error\nMap is missing in .cub file\n"
# define ERR_TEXTURE_PATH "Error\nFile \"%s\" not found\n"
# define ERR_NO_ARG "Error\nExpected at least 1 argument\n"
# define ERR_CRT_IMG "Error\nFailed to create image (mlx error)\n"
# define ERR_MAP_NAME "Error\n%s does not exist\n"
# define ERR_PAR_AFTER_MAP "Error\nParameter after definition of the map\n"
# define ERR_MAP_LEAKS "Error\nMap has leaks\n"
# define ERR_DOUBLE_DEF "Error\nMultiple definitions in .cub\n"
# define ERR_COLOR_FORMAT "Error\nWrong format for color R,G,B [0, 255]\n"
# define ERR_COLOR_MISS "Error\nColor is missing in .cub file\n"
# define ERR_SHORT_LINE "Error\nLine %i is too short (minimum 3 char)\n"
# define MSG1 "\nDo you want to correct the map : 'yes' or 'no'\n"
# define MSG2 "If you accept, the next maps will be automatically corrected\n"
# define MSG3 "'yes' or 'no' only\n"
# define ERR_UNKNOW_PARAM "Error\nUnkown parameter '%s'\n"
# define ERR_PARAM_IN_MAP "Error\nParamater declarated inside the map\n"
# define ERR_WRONG_EXTENTION "Error\nWrong extenstion for file '%s'\n"
# define ERR_UNKNOW_OPTION "Error\nOption '%s' unkown\n"
#endif
