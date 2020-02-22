/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 20:48:48 by bbellavi          #+#    #+#             */
/*   Updated: 2020/02/22 13:17:17 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#   ifndef FT_GAME_H
#   define FT_GAME_H

#include <stdlib.h>
#include "cub3d.h"
#include "parser.h"
#include "utils.h"
#include <math.h>

#   define CHUNK_SIZE 64
#   define WALL '1'
#   define MAX_ANGLE 360
#   define FOV 60

typedef enum    e_cardinals_degree
{
    D_NORTH = 90,
    D_SOUTH = 270,
    D_EAST = 0,
    D_WEST = 180,
}               t_cardinals_degree;

typedef struct	s_player
{
	int heading;
	int curr_x;
	int curr_y;
	int FOVmin;
	int FOVmax;
}				t_player;

enum	e_facing
{
	DOWN,
	UP,
	RIGHT,
	LEFT
};

void    game(t_map *map, t_mlx_infos *infos);
void    init_player(t_player *player);

#   endif