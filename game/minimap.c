/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony <tony@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 16:35:22 by bbellavi          #+#    #+#             */
/*   Updated: 2020/05/09 22:57:53 by tony             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "types.h"
#include "ft_ctypes.h"

void	draw_plan(t_game *data, t_vec2 cp)
{
	draw_img_line(to_vec(cp), (t_vec){(int)cp.x + data->camera.plan_front.x * SQUARE_SIZE, (int)cp.y + data->camera.plan_front.y * SQUARE_SIZE},
		data,
		0xFF00FF
	);
	draw_img_line(to_vec(cp), (t_vec){(int)cp.x + data->camera.plan_right.x * SQUARE_SIZE, (int)cp.y + data->camera.plan_right.y * SQUARE_SIZE},
		data,
		0xFF0000
	);
}

void    minimap_raycaster(t_game *data, t_vec2 pos)
{
	t_vec2	ray;
	size_t	index;

	index = 0;
	while (index < RAYS_NUMBER)
	{
		ray = data->camera.rays[index].dir;
		ray = mult_vec2(ray, SQUARE_SIZE);
		ray = add_vec2(ray, pos);
		draw_img_line(to_vec(pos), to_vec(ray), data, 0xFF00FF);
		index++;
	}
}

void	minimap(t_game *data)
{
	t_vec2	cp;
	t_vec	vi;
	t_vec	i;
	t_vec	s;

	vi.y = 0;
	s = (typeof(s)){SQUARE_SIZE, SQUARE_SIZE};
	cp = (typeof(cp)){data->camera.pos.x * SQUARE_SIZE, data->camera.pos.y * SQUARE_SIZE};
	while (vi.y < data->map.map_ysize)
	{
		vi.x = 0;
		while (vi.x < data->map.map_xsize)
		{
			i.x = vi.x * SQUARE_SIZE;
			i.y = vi.y * SQUARE_SIZE;
			draw_rect(i, s, &data->image, (is_wall(data->map.map[vi.y][vi.x])) ? 0x000000 : 0xFFFFFF);
			vi.x++;
		}
		vi.y++;
	}	
	if (data->camera.debug)
		draw_plan(data, cp);
	minimap_raycaster(data, cp);
	draw_circle((t_vec){(int)cp.x, (int)cp.y}, 5, &data->image, 0xFF00FF);
}