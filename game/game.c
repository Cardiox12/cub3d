/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 20:33:14 by bbellavi          #+#    #+#             */
/*   Updated: 2020/02/25 14:49:13 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <stdio.h>

static int	is_cardinal_point(char c)
{
	return (c == S_SOUTH || c == S_NORTH || c == S_EAST || c == S_WEST);
}

void	set_heading(t_camera *player, char cardinal_p)
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

void	get_starting_coordinate(t_game *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (data->map->map != NULL)
	{
		while (data->map->map[i] != NULL)
		{
			while (data->map->map[i][j] != '\0')
			{
				if (is_cardinal_point(data->map->map[i][j]))
				{
					data->camera->posX = j;
					data->camera->posY = i;
					set_heading(data->camera, data->map->map[i][j]);
				}
				j++;
			}
			j = 0;
			i++;
		}
	}
}

void	set_ray_dir(t_camera *player)
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

void	raycasting(t_game *data)
{
	double x;
	
	x = 0;
	while (x < data->map->resolution->x)
	{
		data->camera->cameraX = 2 * x / (double)data->map->resolution->x - 1;
		data->camera->rayDirX = data->camera->dirX + data->camera->planX * data->camera->cameraX;
		data->camera->rayDirY = data->camera->dirY + data->camera->planY * data->camera->cameraX;
		data->camera->sideDistX = (data->camera->planX == 0) ? 1 : abs(1 / data->camera->planX);
		data->camera->sideDistY = (data->camera->planY == 0) ? 1 : abs(1 / data->camera->planY);
		set_ray_dir(data->camera);
		// DDA algorithm
		while (data->camera->hit == FALSE)
		{
			if (data->camera->sideDistX < data->camera->sideDistY)
			{
				data->camera->sideDistX += data->camera->sideDistX;
				data->camera->mapX += data->camera->stepX;
				data->camera->side = 0;
			}
			else
			{
				data->camera->sideDistY += data->camera->sideDistY;
				data->camera->mapY += data->camera->stepY;
				data->camera->side = 1;
			}
			if (data->map->map[(int)data->camera->mapX][(int)data->camera->mapY] != '0')
				data->camera->hit = TRUE;
		}
		// We calculate the distance in function of the side that has been touched
		if (data->camera->side == 0)
			data->camera->wallDist = (data->camera->mapX - data->camera->posX + (1 - data->camera->stepX) / 2) / data->camera->rayDirX;
		else
			data->camera->wallDist = (data->camera->mapY - data->camera->posY + (1 - data->camera->stepY) / 2) / data->camera->rayDirY;
		// Now we calculate the line to be drawn
		data->camera->lineHeight = (int)(data->map->resolution->y / data->camera->wallDist);
		data->camera->drawStart = -data->camera->lineHeight / 2 + data->map->resolution->y / 2;
		if (data->camera->drawStart < 0)
			data->camera->drawStart = 0;
		data->camera->drawEnd = data->camera->lineHeight / 2 + data->map->resolution->y / 2;
		if (data->camera->drawEnd >= data->map->resolution->y)
			data->camera->drawEnd = data->map->resolution->y - 1;
		// Colouring every wall with white color
		if (data->camera->side == 1)
			data->infos->color = ft_encode_rgb(255, 255, 255);
		else
			data->infos->color = ft_encode_rgb(255, 255, 0);
		draw_img_vert_line(x, data->camera->drawStart, data->camera->drawEnd, data);
		mlx_put_image_to_window(data->infos->mlx_ptr, data->infos->win_ptr, data->image->img_ref, 0, 0);
	}

}

void	game(t_game *data)
{
	init_player(data->camera);
	get_starting_coordinate(data);
	raycasting(data);
}