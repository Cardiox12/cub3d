/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:45:46 by bbellavi          #+#    #+#             */
/*   Updated: 2020/03/02 13:27:44 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#define BYTE_SIZE 8
#define SLICE_WIDTH 1

static int		get_pos_ptr(int x, int y, t_game *data)
{
	return (y * data->image.line_size + x * (data->image.bits_per_pixel / BYTE_SIZE));
}

static void		set_color(int x, int y, t_game *game)
{
	game->image.img_data_addr[get_pos_ptr(x, y, game)] = game->infos.color;
}

void			draw_img_line(int x0, int y0, int x1, int y1, t_game *game)
{
	int dx = abs(x1 - x0);
	int sx = (x0 < x1) ? 1 : -1;
	int dy = abs(y1 - y0);
	int sy = (y0 < y1) ? 1 : -1; 
	int err = (dx > dy ? dx : -dy) / 2;
	int e2;

	while (1)
	{
		set_color(x0, y0, game);
		if (x0 == x1 && y0 == y1)
			break;
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy; 
			x0 += sx;
		}
		if (e2 < dy)
		{
			err += dx; 
			y0 += sy;
		}
	}
}

#include <stdio.h>

void			draw_img_vert_line(int x, int height, t_game *data)
{
	draw_img_line(x, SLICE_WIDTH, x, height, data);
}

void			reset_img(t_game *data)
{
	ft_memset(
		data->image.img_data_addr, 
		0, 
		sizeof(char) * data->map.resolution.x * data->map.resolution.y * 4
	);
}

void			draw_img_rect(t_rect *rect)
{
	int x1;
	int y1;

	x1 = rect->x;
	y1 = rect->y;
	rect->game->infos.color = rect->color;
	while (y1 < rect->y + rect->height)
	{
		while (x1 < rect->x + rect->width)
		{
			set_color(x1, y1, rect->game);
			x1++;
		}
		x1 = rect->x;
		y1++;
	}
}

void			draw_ceil_and_floor(t_game *data)
{
	t_rect rect;
	
	// Drawing ceil first
	rect.game = data;
	rect.color = data->map.ceil_color;
	rect.height = data->map.resolution.y / 2;
	rect.width = data->map.resolution.x;
	rect.x = 0;
	rect.y = 0;
	draw_img_rect(&rect);
	rect.y = data->map.resolution.y / 2;
	rect.color = data->map.ground_color;
	draw_img_rect(&rect);
}