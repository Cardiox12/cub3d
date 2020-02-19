/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:32:26 by bbellavi          #+#    #+#             */
/*   Updated: 2020/02/19 15:53:29 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics_utils.h"

void	rect(int x, int y, int w, int h, t_mlx_infos *infos)
{
	int x1;
	int y1;

	x1 = x;
	y1 = y;
	while (y1 < y + h)
	{
		while (x1 < x + w)
		{
			mlx_pixel_put(infos->mlx_ptr, infos->win_ptr, x1, y1, 0xFFFFFF);
			x1++;
		}
		x1 = x;
		y1++;
	}
}