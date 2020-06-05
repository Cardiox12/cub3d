/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:45:46 by bbellavi          #+#    #+#             */
/*   Updated: 2020/06/05 17:11:17 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

uint32_t	get_color(t_image *img, t_vec pos, int w)
{
	return (img->img_data_addr[pos.x + pos.y * w]);
}

void		set_color(t_game *data, t_vec pos, int color)
{
	const int w = data->map.resolution.x;

	if (pos.x >= 0 && pos.x < data->map.resolution.x
	&& pos.y >= 0 && pos.y < data->map.resolution.y)
	{
		data->image.img_data_addr[pos.y * w + pos.x] = color;
	}
}

void		draw_img_line(t_vec a, t_vec b, t_game *data, uint32_t color)
{
	const t_vec	delta = (t_vec){abs(b.x - a.x), abs(b.y - a.y)};
	const t_vec	s = (t_vec){(a.x < b.x) ? 1 : -1, (a.y < b.y) ? 1 : -1};
	int			err;
	int			e2;

	err = ((delta.x > delta.y) ? delta.x : -delta.y) / 2;
	while (TRUE)
	{
		set_color(data, a, color);
		if (a.x == b.x && a.y == b.y)
			break ;
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

void		draw_img_vert_line(int x, t_vec draw, t_game *data, uint32_t color)
{
	const t_vec a = (t_vec){x, draw.x};
	const t_vec b = (t_vec){x, draw.y};

	draw_img_line(a, b, data, color);
}

void		draw_ceil_and_floor(t_game *data)
{
	t_vec size;

	size = (t_vec){
		data->map.resolution.x,
		data->map.resolution.y / 2
	};
	draw_rect((t_vec){0, 0}, size, &data->image, data->map.ceil_color);
	draw_rect((t_vec){0, data->map.resolution.y / 2},
	size, &data->image, data->map.floor_color);
}
