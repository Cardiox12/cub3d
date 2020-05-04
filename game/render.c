/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 20:33:14 by bbellavi          #+#    #+#             */
/*   Updated: 2020/05/04 23:11:55 by bbellavi         ###   ########.fr       */
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
		data->camera.side_dist.y= (data->camera.map_pos.y + 1.0 - data->camera.pos.y) * data->camera.delta_dist.y;
	}
}

void	raycasting(t_game *data)
{
	uint32_t	color;
	t_vec		draw;
	int			x;

	x = 0;
	color = 0x00FF00;
	while (x < data->map.resolution.x)
	{
		//calculate ray position and direction
		data->camera.cameraX = 2 * x / (double)data->map.resolution.x - 1;
		data->camera.ray_dir.x = data->camera.plan_front.x * data->camera.cameraX;
		data->camera.ray_dir.y = data->camera.plan_front.y * data->camera.cameraX;

		//which box of the map we're in
		data->camera.map_pos = to_vec(data->camera.pos);
		
		data->camera.delta_dist.x = fabs(1 / data->camera.ray_dir.x);
		data->camera.delta_dist.y = fabs(1 / data->camera.ray_dir.y);

		//calculate step and initial sideDist
		get_side(data);
		while (TRUE)
		{
			if(data->camera.side_dist.x < data->camera.side_dist.y)
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
			if (data->map.map[data->camera.map_pos.y][data->camera.map_pos.x] == WALL)
				break;
		}

		//Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
		if (data->camera.side == 0)
			data->camera.perp_wall_dist = (data->camera.map_pos.x - data->camera.pos.x + (1 - data->camera.step.x) / 2) / data->camera.ray_dir.x;
		else
			data->camera.perp_wall_dist = (data->camera.map_pos.y - data->camera.pos.y + (1 - data->camera.step.y) / 2) / data->camera.ray_dir.y;

		data->camera.line_height = (data->map.resolution.y / data->camera.perp_wall_dist);
		
		//calculate lowest and highest pixel to fill in current stripe
		data->camera.draw_start = -data->camera.line_height / 2 + data->map.resolution.y / 2;
		if (data->camera.draw_start < 0)
			data->camera.draw_start = 0;
		data->camera.draw_end = data->camera.line_height / 2 + data->map.resolution.y / 2;
		if (data->camera.draw_end >= data->map.resolution.y)
			data->camera.draw_end = data->map.resolution.y - 1;

		if (data->camera.side == 1)
			color = color / 2;

		draw = (typeof(draw)){data->camera.draw_start, data->camera.draw_end};
		draw_img_vert_line(x, draw, data, color);
		x++;
	}
}

void	render(t_game *data)
{
	draw_ceil_and_floor(data);
	raycasting(data);
	minimap(data);
}