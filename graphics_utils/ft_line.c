/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 01:15:33 by bbellavi          #+#    #+#             */
/*   Updated: 2020/02/24 17:09:32 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics_utils.h"

void    line(int x0, int y0, int x1, int y1, t_mlx_infos *infos)
{
	int dx = abs(x1 - x0);
	int sx = (x0 < x1) ? 1 : -1;
	int dy = abs(y1 - y0);
	int sy = (y0 < y1) ? 1 : -1; 
	int err = (dx > dy ? dx : -dy) / 2;
	int e2;

	while (1)
	{
		mlx_pixel_put(infos->mlx_ptr, infos->win_ptr, x0, y0, infos->color);
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