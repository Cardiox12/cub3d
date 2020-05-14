/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:45:46 by bbellavi          #+#    #+#             */
/*   Updated: 2020/05/14 12:32:05 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#define BYTE_SIZE 8
#define SLICE_WIDTH 1

uint32_t	get_color(t_image *img, t_vec pos, int w)
{
	return (img->img_data_addr[pos.x + pos.y * w]);
}

void		set_color(t_game *data, t_vec pos, int color)
{
	const int w = data->map.resolution.x;

	if (pos.x >= 0 && pos.x < data->map.resolution.x && pos.y >= 0 && pos.y < data->map.resolution.y)
	{
		data->image.img_data_addr[pos.y * w + pos.x] = color;
	}
}

void			draw_img_line(t_vec a, t_vec b, t_game *data, uint32_t color)
{
	const t_vec delta = (t_vec){abs(b.x - a.x), abs(b.y - a.y)};
	const t_vec s = (t_vec){(a.x < b.x) ? 1 : -1, (a.y < b.y) ? 1 : -1};
	int err = (delta.x > delta.y ? delta.x : -delta.y) / 2;
	int e2;

	while (TRUE)
	{
		set_color(data, a, color);
		if (a.x == b.x && a.y == b.y)
			break;
		e2 = err;
		if (e2 > -delta.x)
		{
			err -= delta.y;
			a.x += s.x;
		}
		if (e2 < delta.y)
		{
			err += delta.x;
			a.y += s.y;
		}
	}
}

void			draw_img_vert_line(int x, t_vec draw, t_game *data, uint32_t color)
{
	const t_vec a = (t_vec){x, draw.x};
	const t_vec b = (t_vec){x, draw.y};
	
	draw_img_line(a, b, data, color);
}

void			reset_img(t_game *data)
{
	ft_memset(
		data->image.img_data_addr, 
		0, 
		sizeof(char) * data->map.resolution.x * data->map.resolution.y * 4
	);
}

void			draw_ceil_and_floor(t_game *data)
{
	const t_vec size = (t_vec){data->map.resolution.x, data->map.resolution.y / 2};

	draw_rect((t_vec){0, 0}, size, &data->image, data->map.ceil_color);
	draw_rect((t_vec){0, data->map.resolution.y / 2}, size, &data->image, data->map.ground_color);
}

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
