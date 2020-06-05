/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 23:14:30 by tony              #+#    #+#             */
/*   Updated: 2020/06/05 21:22:08 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "render.h"

static void    perform_dda(t_game *data)
{
	while (TRUE)
	{
		if (data->camera.side_dist.x < data->camera.side_dist.y)
		{
			data->camera.side_dist.x += data->camera.delta_dist.x;
			data->camera.map_pos.x += data->camera.step.x;
			data->camera.side = 0;
		}
		else
		{
			data->camera.side_dist.y += data->camera.delta_dist.y;
			data->camera.map_pos.y += data->camera.step.y;
			data->camera.side = 1;
		}
		if (is_wall(data->map.map[data->camera.map_pos.y][data->camera.map_pos.x]))
			return ;
	}
}

static void    get_perp_dist(t_game *data)
{
	const int	h = data->map.resolution.y;
	//Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)

	if (data->camera.side == 0)
		data->camera.perp_wall_dist = (data->camera.map_pos.x - data->camera.pos.x + (1 - data->camera.step.x) / 2) / data->camera.ray_dir.x;
	else
		data->camera.perp_wall_dist = (data->camera.map_pos.y - data->camera.pos.y + (1 - data->camera.step.y) / 2) / data->camera.ray_dir.y;

	data->camera.line_height = (int)(h / data->camera.perp_wall_dist);
	//calculate lowest and highest pixel to fill in current stripe
	data->camera.draw_start = -data->camera.line_height / 2 + h / 2;
	if (data->camera.draw_start < 0)
		data->camera.draw_start = 0;
	data->camera.draw_end = data->camera.line_height / 2 + h / 2;
	if (data->camera.draw_end >= h)
		data->camera.draw_end = h - 1;
}

static void    init_raycast_variables(t_game *data, int x)
{
	data->camera.camera_x = 2 * x / (double)data->map.resolution.x - 1;
	data->camera.ray_dir.x = data->camera.plan_front.x + data->camera.plan_right.x * data->camera.camera_x;
	data->camera.ray_dir.y = data->camera.plan_front.y + data->camera.plan_right.y * data->camera.camera_x;
	data->camera.map_pos = to_vec(data->camera.pos);
	data->camera.ray_dir.x = (data->camera.ray_dir.x == 0) ? 1 : data->camera.ray_dir.x;
	data->camera.ray_dir.y = (data->camera.ray_dir.y == 0) ? 1 : data->camera.ray_dir.y;
	data->camera.delta_dist.x = fabs(1 / data->camera.ray_dir.x);
	data->camera.delta_dist.y = fabs(1 / data->camera.ray_dir.y);
}

void	raycasting(t_game *data)
{
	int x;

	x = 0;
	while (x < data->map.resolution.x)
	{
		init_raycast_variables(data, x);
		get_side(data);
		perform_dda(data);
		get_perp_dist(data);
		map_texture(data, x);
		data->camera.zbuffer[x] = data->camera.perp_wall_dist;
		x++;
	}
	cast_sprites(data);
}