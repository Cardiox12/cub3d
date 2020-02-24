/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 20:33:14 by bbellavi          #+#    #+#             */
/*   Updated: 2020/02/24 17:58:13 by bbellavi         ###   ########.fr       */
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
	{
		player->posX = 0;
		player->posY = 1;
	}
	else if (cardinal_p == S_NORTH)
	{
		player->heading = D_NORTH;
		player->posX = 0;
		player->posY = -1;
	}
	else if (cardinal_p == S_WEST)
	{
		player->posX = -1;
		player->posY = 0;
	}
	else if (cardinal_p == S_EAST)
	{
		player->posX = 1;
		player->posY = 0;
	}
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
					player->posX = j;
					player->posY = i;
					set_heading(player, map->map[i][j]);
				}
				j++;
			}
			j = 0;
			i++;
		}
	}
}

void	set_ray_dir(t_player *player)
{
	if (player->rayDirX < 0)
	{
		player->stepX = -1;
		player->sideDistX = (player->posX - player->mapX) * player->deltaDistX;
	}
	else
	{
		player->stepX = 1;
		player->sideDistX = (player->mapX + 1.0 - player->posX) * player->deltaDistX;
	}
	if (player->rayDirY < 0)
	{
		player->stepY = -1;
		player->sideDistY = (player->posY - player->mapY) * player->deltaDistY;
	}
	else
	{
		player->stepX = 1;
		player->sideDistX = (player->mapY + 1.0 - player->posY) * player->deltaDistY;
	}
}

void	raycasting(t_player *player, t_map *map)
{
	double x;
	
	x = 0;
	while (x < map->resolution->x)
	{
		player->cameraX = 2 * x / (double)map->resolution->x - 1;
		player->rayDirX = player->dirX + player->planX * player->cameraX;
		player->rayDirY = player->dirY + player->planY * player->cameraX;
		player->sideDistX = (player->planX == 0) ? 1 : abs(1 / player->planX);
		player->sideDistY = (player->planY == 0) ? 1 : abs(1 / player->planY);
		set_ray_dir(player);
		// DDA algorithm
		while (player->hit == FALSE)
		{
			if (player->sideDistX < player->sideDistY)
			{
				player->sideDistX += player->sideDistX;
				player->mapX += player->stepX;
				player->side = 0;
			}
			else
			{
				player->sideDistY += player->sideDistY;
				player->mapY += player->stepY;
				player->side = 1;
			}
			if (map->map[(int)player->mapX][(int)player->mapY] != '0')
				player->hit = TRUE;
		}
		// We calculate the distance in function of the side that has been touched
		if (player->side == 0)
			player->wallDist = (player->mapX - player->posX + (1 - player->stepX) / 2) / player->rayDirX;
		else
			player->wallDist = (player->mapY - player->posY + (1 - player->stepY) / 2) / player->rayDirY;
		// Now we calculate the line to be drawn
		player->lineHeight = (int)(map->resolution->y / player->wallDist);
		player->drawStart = -player->lineHeight / 2 + map->resolution->y / 2;
		if (player->drawStart < 0)
			player->drawStart = 0;
		player->drawEnd = player->lineHeight / 2 + map->resolution->y / 2;
		if (player->drawEnd >= map->resolution->y)
			player->drawEnd = map->resolution->y - 1;
		// Colouring every wall with white color
		if (player->side == 1)
			player->infos->color = ft_encode_rgb(255, 255, 255);
		line(x, player->drawStart, x, player->drawEnd, player->infos);
	}
}

void	game(t_map *map, t_mlx_infos *infos)
{
	t_player	player;
	
	init_player(&player);
	player.infos = infos;
	get_starting_coordinate(map, &player);
	raycasting(&player, map);
}