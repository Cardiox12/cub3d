/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony <tony@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 20:33:14 by bbellavi          #+#    #+#             */
/*   Updated: 2020/04/27 21:57:35 by tony             ###   ########.fr       */
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

	// player->fov_left = rotate(player->plan_front, to_radians(player->field_of_view / 2), ANTI_CLOCKWISE);
	// player->fov_right = rotate(player->plan_front, to_radians(player->field_of_view / 2), CLOCKWISE);
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
	if (data->camera.rayDirX < 0)
	{
		data->camera.stepX = -1;
		data->camera.sideDistX = (data->camera.pos.x - data->camera.mapX);
	}
	else
	{
		data->camera.stepX = 1;
		data->camera.sideDistX = (data->camera.mapX + 1.0 - data->camera.pos.x) * data->camera.deltaDistX;
	}
	if (data->camera.rayDirY < 0)
	{
		data->camera.stepY = -1;
		data->camera.sideDistY = (data->camera.pos.y - data->camera.mapY) * data->camera.deltaDistY;
	}
	else
	{
		data->camera.stepY = 1;
		data->camera.sideDistY = (data->camera.mapY + 1.0 - data->camera.pos.y) * data->camera.deltaDistX;
	}
}

void	raycasting(__unused t_game *data)
{
	
}

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

// void	draw_fov(t_game *data, t_vec2 cp)
// {	
// 	draw_img_line(to_vec(cp), (t_vec){(int)cp.x + data->camera.fov_left.x * SQUARE_SIZE, (int)cp.y + data->camera.fov_left.y * SQUARE_SIZE},
// 		data,
// 		0xFF00FF
// 	);
// 	draw_img_line(to_vec(cp), (t_vec){(int)cp.x + data->camera.fov_right.x * SQUARE_SIZE, (int)cp.y + data->camera.fov_right.y * SQUARE_SIZE},
// 		data,
// 		0xFF00FF
// 	);
// }

void    minimap_raycaster(t_game *data, t_vec2 pos)
{
	t_vec proj;
	t_ray	ray;
	int index;

    index = 0;
    while (index < RAYS_NUMBER)
    {   
		ray = data->camera.rays[index];
		ray.pos = pos;
		proj = add_vec(to_vec(pos), to_vec(mult_vec2(ray.dir, 50)));
		draw_img_line(to_vec(ray.pos), proj, data, 0xFF00FF);
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
			draw_rect(i, s, &data->image, (data->map.map[vi.y][vi.x] == '1') ? 0x000000 : 0xFFFFFF);
			vi.x++;
		}
		vi.y++;
	}
	if (data->camera.debug)
		draw_plan(data, cp);
	// draw_fov(data, cp);
	minimap_raycaster(data, cp);
	draw_circle((t_vec){(int)cp.x, (int)cp.y}, 5, &data->image, 0xFF00FF);
}

void	render(t_game *data)
{
	draw_ceil_and_floor(data);
	minimap(data);
}