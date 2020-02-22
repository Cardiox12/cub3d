/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 20:33:14 by bbellavi          #+#    #+#             */
/*   Updated: 2020/02/22 14:43:54 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <stdio.h>

static int	is_cardinal_point(char c)
{
	return (c == S_SOUTH || c == S_NORTH || c == S_EAST || c == S_WEST);
}

void	set_heading(t_player *player, char cardinal_p)
{
	if (cardinal_p == S_SOUTH)
		player->heading = D_SOUTH;
	else if (cardinal_p == S_NORTH)
		player->heading = D_NORTH;
	else if (cardinal_p == S_WEST)
		player->heading = D_WEST;
	else if (cardinal_p == S_EAST)
		player->heading = D_EAST;
}

void	get_starting_coordinate(t_map *map, t_player *player)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (map->map != NULL)
	{
		while (map->map[i] != NULL)
		{
			while (map->map[i][j] != '\0')
			{
				if (is_cardinal_point(map->map[i][j]))
				{
					player->curr_x = j;
					player->curr_y = i;
					set_heading(player, map->map[i][j]);
				}
				j++;
			}
			j = 0;
			i++;
		}
	}
}

int		is_not_limit(t_map *map, int x, int y)
{
	return (x >= 0 && x < map->map_xsize && y >= 0 && y < map->map_ysize);
}

int		collide(t_map *map, int x, int y)
{
	int rx;
	int ry;

	rx = x / CHUNK_SIZE;
	ry = y / CHUNK_SIZE;
	if (is_not_limit(map, x, y))
	{
		if (map->map[ry][rx] == WALL)
			return (TRUE);
	}
	return (FALSE);
}

int		angle(int degree)
{
    if (degree < 0)
        return (MAX_ANGLE + degree % MAX_ANGLE);
    return (degree % MAX_ANGLE);
}

float	to_radian(int degree)
{
	return (degree * M_PI / 180);
}

int		get_vertical_facing(t_player *player)
{
	if (player->heading >= 180 && player->heading <= 360)
		return (LEFT);
	return (RIGHT);
}

int		get_horizontal_facing(t_player *player)
{
	if ((player->heading >= 0 && player->heading <= 90) || (player->heading >= 270 && player->heading <= 360))
		return (UP);
	return (DOWN);
}

int		check_horizontal(__unused t_map *map, t_player *player, __unused int px, __unused int py)
{
	// 1. Finding the coordinate of A.

	// If the ray is facing up
	// 	A.y = rounded_down(Py / 64) * (64) - 1;
	// If the ray is facing down
	// 	A.y = rounded_down(Py / 64) * (64) + 64;

	int ay;
	
	ay = round(py / CHUNK_SIZE) * CHUNK_SIZE - 1;
	print_facing(horizontal_facing(player));
	print_facing(vertical_facing(player));
	return (ay);
}

void    cast_1(t_map *map, t_player *player)
{
	int alpha;
	int max;

	// Alpha take the current angle for every angle in the the range FOVmin - FOVmax    
	alpha = player->FOVmin;
	max = player->FOVmax;
	check_horizontal(map, player, 0, 0);
}

void    cast(t_map *map, t_player *player)
{
	player->FOVmin = angle(player->heading - FOV / 2);
	player->FOVmax = angle(player->heading + FOV / 2);

	if (player->FOVmin < player->FOVmax)
		cast_1(map, player);
}

void	game(t_map *map, __unused t_mlx_infos *infos)
{
	t_player	player;

	get_starting_coordinate(map, &player);
	cast(map, &player);
}