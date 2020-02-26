/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 20:33:14 by bbellavi          #+#    #+#             */
/*   Updated: 2020/02/26 14:20:20 by bbellavi         ###   ########.fr       */
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
		player->planX = 0;
		player->planY = 1;
	}
	else if (cardinal_p == S_NORTH)
	{
		player->heading = D_NORTH;
		player->planX = 0;
		player->planY = -1;
	}
	else if (cardinal_p == S_WEST)
	{
		player->planX = -1;
		player->planY = 0;
	}
	else if (cardinal_p == S_EAST)
	{
		player->planX = 1;
		player->planY = 0;
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
	data->camera->mapX = data->camera->posX;
	data->camera->mapY = data->camera->posY;
	while (x < data->infos->width)
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
			data->infos->color = ft_encode_rgb(255, 255, 200);
		else
			data->infos->color = 0xFFC0CB;
		draw_img_vert_line(x, data->camera->drawStart, data);
		x++;
	}
	mlx_put_image_to_window(data->infos->mlx_ptr, data->infos->win_ptr, data->image->img_ref, 0, 0);
}

void	print_data(t_game *data)
{
	printf("side : %i\n", data->camera->side);
	printf("hit : %i\n", data->camera->hit);
	printf("heading : %i\n", data->camera->heading);
	printf("posX : %i\n", data->camera->posX);
	printf("posY : %i\n", data->camera->posY);
	printf("dirX : %i\n", data->camera->dirX);
	printf("dirY : %i\n", data->camera->dirY);
	printf("planX : %i\n", data->camera->planX);
	printf("planY : %i\n", data->camera->planY);
	printf("rayDirX : %f\n", data->camera->rayDirX);
	printf("rayDirY : %f\n", data->camera->rayDirY);
	printf("cameraX : %f\n", data->camera->cameraX);
	printf("mapX : %f\n", data->camera->mapX);
	printf("mapY : %f\n", data->camera->mapY);
	printf("sideDistX : %f\n", data->camera->sideDistX);
	printf("sideDistY : %f\n", data->camera->sideDistY);
	printf("deltaDistX : %f\n", data->camera->deltaDistX);
	printf("deltaDistY : %f\n", data->camera->deltaDistY);
	printf("stepX : %f\n", data->camera->stepX);
	printf("stepY : %f\n", data->camera->stepY);
	printf("wallDist : %f\n", data->camera->wallDist);
	printf("drawStart : %i\n", data->camera->drawStart);
	printf("drawEnd : %i\n", data->camera->drawEnd);
	printf("line height : %i\n", data->camera->lineHeight);
}

void	game(t_game *data)
{
	init_player(data->camera);
	get_starting_coordinate(data);
	draw_ceil_and_floor(data);
	raycasting(data);
	print_data(data);
	mlx_put_image_to_window(data->infos->mlx_ptr, data->infos->win_ptr, data->image->img_ref, 0, 0);
}