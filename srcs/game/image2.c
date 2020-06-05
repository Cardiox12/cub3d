/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 17:05:45 by bbellavi          #+#    #+#             */
/*   Updated: 2020/06/05 17:12:26 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	draw_rect(t_vec pos, t_vec size, t_image *img, uint32_t color)
{
	const int	w = img->line_size / 4;
	t_vec		i;

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

int		nearer(t_vec *a, t_vec *b, int max_dist)
{
	return (
		((a->x - b->x) * (a->x - b->x) + (a->y - b->y) * (a->y - b->y))
		< max_dist * max_dist);
}

void	draw_circle(t_vec pos, int radius, t_image *img, uint32_t color)
{
	const int	w = img->line_size / 4;
	t_vec		i;

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
