/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 20:33:14 by bbellavi          #+#    #+#             */
/*   Updated: 2020/02/19 15:57:42 by bbellavi         ###   ########.fr       */
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

int		collide(t_map *map, int x, int y)
{
	int rx;
	int ry;

	rx = x / CHUNK_SIZE;
	ry = y / CHUNK_SIZE;
	if (rx >= 0 && rx < map->map_xsize && ry >= 0 && ry < map->map_ysize)
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

void    cast_1(t_map *map, t_player *player)
{
	int alpha;
	int max;
	int x;
	int y;

	// Alpha take the current angle for every angle in the the range FOVmin - FOVmax    
	alpha = player->FOVmin;
	max = player->FOVmax;
	y = player->curr_y * CHUNK_SIZE;
	x = player->curr_x * CHUNK_SIZE;
	while (alpha < max)
	{
		// Draw until collision
		while (collide(map, x, y) == 0)
		{
			x += CHUNK_SIZE / tan(to_radian(alpha));
			y += CHUNK_SIZE;
			if (collide(map, x, y))
				printf("COLLISION\n");
		}
		alpha++;
	}
	printf("NO COLLISION\n");
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