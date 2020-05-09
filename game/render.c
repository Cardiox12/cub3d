/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony <tony@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 20:33:14 by bbellavi          #+#    #+#             */
/*   Updated: 2020/05/09 23:14:27 by tony             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include <stdio.h>
#include "errors.h"

int		is_cardinal_point(char c)
{
	return (c == S_SOUTH || c == S_NORTH || c == S_EAST || c == S_WEST);
}

void	set_heading(t_camera *player, char cardinal_p)
{
	player->plan_front = (t_vec2){0.0f, -1.0f};
	player->plan_right = (t_vec2){1.0f, 0.0f};
	if (cardinal_p == S_SOUTH)
		player->camera_angle = to_radians(ANGLE_south);
	else if (cardinal_p == S_NORTH)
		player->camera_angle = to_radians(ANGLE_north);
	else if (cardinal_p == S_WEST)
		player->camera_angle = to_radians(ANGLE_west);
	else if (cardinal_p == S_EAST)
		player->camera_angle = to_radians(ANGLE_east);
		

	player->plan_front = rotate(player->plan_front, player->camera_angle, CLOCKWISE);
	player->plan_right = rotate(player->plan_right, player->camera_angle, CLOCKWISE);
}

int		get_starting_point(t_game *data)
{
	t_vec i;

	i = (typeof(i)){0, 0};
	while (i.y < data->map.map_ysize)
	{
		while (i.x < data->map.map_xsize)
		{
			if (is_cardinal_point(data->map.map[i.y][i.x]))
			{
				set_heading(&data->camera, data->map.map[i.y][i.x]);
				data->camera.pos.x = i.x;
				data->camera.pos.y = i.y;
				return (FOUND);
			}	
			i.x++;
		}
		i.x = 0;
		i.y++;
	}
	return (NOT_FOUND);
}

void	get_side(t_game *data)
{
	if (data->camera.ray_dir.x < 0)
	{
		data->camera.step.x = -1;
		data->camera.side_dist.x = (data->camera.pos.x - data->camera.map_pos.x) * data->camera.delta_dist.x;
	}
	else
	{
		data->camera.step.x = 1;
		data->camera.side_dist.x = (data->camera.map_pos.x + 1.0 - data->camera.pos.x) * data->camera.delta_dist.x;
	}
	if (data->camera.ray_dir.y < 0)
	{
		data->camera.step.y = -1;
		data->camera.side_dist.y = (data->camera.pos.y - data->camera.map_pos.y) * data->camera.delta_dist.y;
	}
	else
	{
		data->camera.step.y = 1;
		data->camera.side_dist.y = (data->camera.map_pos.y + 1.0 - data->camera.pos.y) * data->camera.delta_dist.y;
	}
}

void	render(t_game *data)
{
	draw_ceil_and_floor(data);
	raycasting(data);
	minimap(data);
}