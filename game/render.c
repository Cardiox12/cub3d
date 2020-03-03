/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 20:33:14 by bbellavi          #+#    #+#             */
/*   Updated: 2020/03/03 14:42:37 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include <stdio.h>
#include "errors.h"

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

int		get_starting_point(t_game *data)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < data->map.map_ysize)
	{
		while (x < data->map.map_xsize)
		{
			if (is_cardinal_point(data->map.map[y][x]))
			{
				set_heading(&data->camera, data->map.map[y][x]);
				data->camera.posX = x;
				data->camera.posX = y;
				return (FOUND);
			}	
			x++;
		}
		x = 0;
		y++;
	}
	return (NOT_FOUND);
}

void	get_side(t_game *data)
{
	if (data->camera.rayDirX < 0)
	{
		data->camera.stepX = -1;
		data->camera.sideDistX = (data->camera.posX - data->camera.mapX);
	}
	else
	{
		data->camera.stepX = 1;
		data->camera.sideDistX = (data->camera.mapX + 1.0 - data->camera.posX) * data->camera.deltaDistX;
	}
	if (data->camera.rayDirY < 0)
	{
		data->camera.stepY = -1;
		data->camera.sideDistY = (data->camera.posY - data->camera.mapY) * data->camera.deltaDistY;
	}
	else
	{
		data->camera.stepY = 1;
		data->camera.sideDistY = (data->camera.mapY + 1.0 - data->camera.posY) * data->camera.deltaDistX;
	}
}

void	raycasting(t_game *data)
{
	int x;

	x = 0;
	while (x < data->map.resolution.x)
	{
		data->camera.cameraX = 2 * data->map.resolution.x - 1;

		data->camera.rayDirX = data->camera.dirX + data->camera.planX * data->camera.cameraX;
		data->camera.rayDirY = data->camera.dirY + data->camera.planY * data->camera.cameraX;
		
		data->camera.mapX = data->camera.posX;
		data->camera.mapY = data->camera.posY;

		data->camera.deltaDistX = fabs(1 / data->camera.rayDirX);
		data->camera.deltaDistY = fabs(1 / data->camera.rayDirY);

		data->camera.hit = 0;

		get_side(data);

		// Make DDA algorithm
		while (data->camera.hit == FALSE)
		{
			if (data->camera.sideDistX < data->camera.sideDistY)
			{
				data->camera.sideDistX += data->camera.deltaDistX;
				data->camera.mapY += data->camera.stepX;
				data->camera.side = 0;
			}
			else
			{
				data->camera.sideDistY += data->camera.deltaDistY;
				data->camera.mapX += data->camera.stepY;
				data->camera.side = 1;
			}
			if (data->map.map[(int)data->camera.mapY][(int)data->camera.mapX] != '0')
				data->camera.hit = 0;
		}
		if (data->camera.side == 0)
			data->camera.wallDist = (data->camera.mapX - data->camera.posX + (1 - data->camera.stepX) / 2) / data->camera.rayDirX;
		else
			data->camera.wallDist = (data->camera.mapY - data->camera.posY + (1 - data->camera.stepY) / 2) / data->camera.rayDirY;
		
		data->camera.lineHeight = (int)(data->map.resolution.y / data->camera.wallDist);
		
		data->camera.drawStart = -data->camera.lineHeight / 2 + data->map.resolution.y / 2;
		if (data->camera.drawStart < 0)
			data->camera.drawStart = 0;
		data->camera.drawEnd = data->camera.lineHeight / 2 + data->map.resolution.y / 2;
		if (data->camera.drawEnd >= data->map.resolution.y)
			data->camera.drawEnd = data->map.resolution.y;

		draw_img_vert_line(x, abs(data->camera.drawStart - data->camera.drawEnd), data);
		x++;
	}
}

void	render(t_game *data)
{
	data->image.img_ref = mlx_new_image(
			data->infos.mlx_ptr,
			data->map.resolution.x,
			data->map.resolution.y);
	data->image.img_data_addr = (int*)mlx_get_data_addr(
		data->image.img_ref,
		&data->image.bits_per_pixel,
		&data->image.line_size,
		&data->image.endian);
		
	draw_ceil_and_floor(data);

	mlx_put_image_to_window(
		data->infos.mlx_ptr,
		data->infos.win_ptr,
		data->image.img_ref,
		0,
		0
	);
	mlx_destroy_image(
		data->infos.mlx_ptr,
		data->image.img_ref
	);
	raycasting(data);
}