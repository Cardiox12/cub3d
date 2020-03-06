/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:45:46 by bbellavi          #+#    #+#             */
/*   Updated: 2020/03/06 18:45:40 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#define BYTE_SIZE 8
#define SLICE_WIDTH 1

static void		set_color(t_game *data, int x, int y, int color)
{
	const int w = data->map.resolution.x;

	if (x >= 0 && x < data->map.resolution.x && y >= 0 && y < data->map.resolution.y)
	{
		data->image.img_data_addr[y * w + x] = color;
	}
}

void			draw_img_line(int x0, int y0, int x1, int y1, t_game *data)
{
	int dx = abs(x1 - x0);
	int sx = (x0 < x1) ? 1 : -1;
	int dy = abs(y1 - y0);
	int sy = (y0 < y1) ? 1 : -1; 
	int err = (dx > dy ? dx : -dy) / 2;
	int e2;

	while (TRUE)
	{
		set_color(data, x0, y0, data->infos.color);
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
	while (y1 < rect->y + rect->height)
	{
		while (x1 < rect->x + rect->width)
		{
			set_color(rect->game, x1, y1, rect->color);
			x1++;
		}
		x1 = rect->x;
		y1++;
	}
}

void			draw_ceil_and_floor(t_game *data)
{
	t_rect rect;
	
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

#include <stdio.h>

void			draw_rect(t_vec pos, t_vec size, t_image *img, uint32_t color)
{
	int				w = img->line_size / 4;
	t_vec			i;

	size.x += pos.x;
	size.y += pos.y;
	if ((i.y = pos.y) < 0)
		i.y = 0;
	while (i.y < size.y && i.y < img->line_count)
	{
		if ((i.x = pos.x) < 0)
			i.x = 0;
		while (i.x < size.x && i.x < w)
			img->img_data_addr[i.x++ + i.y * w] = color;
		++i.y;
	}
}

int				nearer(t_vec *a, t_vec *b, int max_dist)
{
	return (
		((a->x - b->x) * (a->x - b->x) + (a->y - b->y) * (a->y - b->y))
		< max_dist * max_dist
	);
}

void			draw_circle(t_vec pos, int radius, t_image *img, uint32_t color)
{
	int				w = img->line_size / 4;
	t_vec			i;

	if ((i.y = pos.y - radius) < 0)
		i.y = 0;
	while (i.y < pos.y + radius && i.y < img->line_count)
	{
		if ((i.x = pos.x - radius) < 0)
			i.x = 0;
		while (i.x >= 0 && i.x < pos.x + radius && i.x < w)
		{
			if (nearer(&pos, &i, radius))
				img->img_data_addr[i.x + i.y * w] = color;
			i.x++;
		}
		++i.y;
	}
}