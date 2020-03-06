/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 02:01:35 by bbellavi          #+#    #+#             */
/*   Updated: 2020/03/06 14:37:22 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#   ifndef FT_PARSER_H
#   define FT_PARSER_H

#include <fcntl.h>
#include "types.h"
#include "graphics_utils.h"

#   define ID_SIZE          8
#   define CUB_EXTENSION    ".cub"
#   define CUB_EXT_LENGTH   4
#   define RES              "R"
#   define NORTH            "NO"
#   define SOUTH            "SO"
#   define WEST             "WE"
#   define EAST             "EA"
#   define SPRITE           "S"
#   define FLOOR            "F"
#   define CEIL             "C"
#   define TRUE             1
#   define FALSE            0
#   define NOT_FOUND        -1
#   define ERR_RESOLUTION   "Bad format for resolution.\n"
#   define ERR_TEXTURE      "Bad format for texture.\n"
#   define ERR_COLORS       "Bad format for colors.\n"
#   define ERR_RGB_RANGE    "Bad range for colors, value must be between [0, 255].\n"
#   define SPACE            ' '
#   define COMMA            ','
#   define MAP_SYMBOLS      "012NSEW"

typedef enum    e_ident
{
    I_NORTH,
    I_SOUTH,
    I_EAST,
    I_WEST,
    I_SPRITE,
    I_CEIL,
    I_FLOOR
}               t_ident;

typedef enum    e_cardinal_p
{
	S_NORTH		= 'N',
	S_SOUTH		= 'S',
	S_EAST		= 'E',
	S_WEST		= 'W'
}               e_cardinal_p;

static char *identifiers[ID_SIZE] = {"R", "NO", "SO", "WE", "EA", "S", "F", "C"};
void    parse_map(const char *path, t_map *map);

#   endif
