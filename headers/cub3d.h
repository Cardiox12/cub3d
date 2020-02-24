/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 01:47:19 by bbellavi          #+#    #+#             */
/*   Updated: 2020/02/24 17:09:02 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#   ifndef FT_CUB3D_H
#   define FT_CUB3D_H

#include <stddef.h>
#include <math.h>
#include <stdlib.h>
#include "mlx.h"

#   define HEIGHT 1000
#   define WIDTH 1000

typedef struct  s_mlx_infos
{
    void    *mlx_ptr;
    void    *win_ptr;
    int     height;
    int     width;
    int     color;
}               t_mlx_infos;

typedef struct  s_vec
{
    int x;
    int y;
}               t_vec;

typedef struct  s_textures
{
    char *north;
    char *south;
    char *west;
    char *east;
    char *sprite;
}               t_textures;

typedef struct  s_map
{
    char        **map;
    t_vec       *resolution;
    t_textures  *textures;
    int         ground_color;
    int         ceil_color;
    int         map_xsize;
    int         map_ysize;
}               t_map;

#include "graphics_utils.h"
#include "utils.h"
#include "event_hooks.h"

#   endif