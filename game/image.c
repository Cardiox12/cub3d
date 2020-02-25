/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:45:46 by bbellavi          #+#    #+#             */
/*   Updated: 2020/02/25 16:25:56 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#define BYTE_SIZE 8


static int		get_pos_ptr(int x, int y, t_game *game)
{
	return (y * game->image->line_size + x * (game->image->bits_per_pixel / BYTE_SIZE));
}

static void		set_color(int x, int y, t_game *game)
{
	game->image->img_data_addr[get_pos_ptr(x, y, game)] = (unsigned int)game->infos->color;
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

void			draw_img_vert_line(int x, int height, int width, t_game *data)
{
	draw_img_line(x, height, x, width, data);
}

void			reset_img(t_game *data)
{
	ft_memset(data->image->img_data_addr, 0, sizeof(char) * data->infos->width * data->infos->height * 4);
}