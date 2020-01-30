/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 02:01:35 by bbellavi          #+#    #+#             */
/*   Updated: 2020/01/30 00:48:21 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#   ifndef FT_PARSER_H
#   define FT_PARSER_H

#include "cub3d.h"
#include <fcntl.h>

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
#   define ERR_RESOLUTION   "Bad format for resolution.\n"

static char *identifiers[ID_SIZE] = {"R", "NO", "SO", "WE", "EA", "S", "F", "C"};
void    parse_map(const char *path, t_map *map);

#   endif
