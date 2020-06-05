/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 20:33:14 by bbellavi          #+#    #+#             */
/*   Updated: 2020/06/05 16:20:49 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include <stdio.h>
#include "errors.h"
#include "bitmap.h"

void	init_rays(t_camera *player)
{
	const float		fov_mid = player->field_of_view / 2;
	const float		step =  player->field_of_view / ((RAYS_NUMBER == 1) ? 1 : RAYS_NUMBER - 1);
	const t_vec2	dir = player->plan_front;
	size_t			index;

	index = 0; 
	while (index < RAYS_NUMBER)
	{
		player->rays[index].pos.x = 0;
		player->rays[index].pos.y = 0;
		player->rays[index].particle.x = 0;
		player->rays[index].particle.y = 0;
		player->rays[index].dir = dir;
		player->rays[index].angle = 0;
		ray_rotate(&player->rays[index], to_radians(step * index), CLOCKWISE);
		index++;
	}
	if (RAYS_NUMBER != 1)
		rays_rotate(player->rays, to_radians(fov_mid), ANTI_CLOCKWISE);
}

int		is_cardinal_point(char c)
{
	return (c == S_SOUTH || c == S_NORTH || c == S_EAST || c == S_WEST);
}

void	set_heading(t_camera *player, char cardinal_p)
{
	float angle;
	
	player->plan_front = (t_vec2){0.0f, -1.0f};
	player->dir = (t_vec2){-1.0f, 0.0f};
	player->plan_right = (t_vec2){player->field_of_view / 100, 0.0f};

	angle = 0.0f;
	if (cardinal_p == S_SOUTH)
		angle = to_radians(ANGLE_SOUTH);
	else if (cardinal_p == S_NORTH)
		angle = to_radians(ANGLE_NORTH);
	else if (cardinal_p == S_WEST)
		angle = to_radians(ANGLE_WEST);
	else if (cardinal_p == S_EAST)
		angle = to_radians(ANGLE_EAST);

	player->plan_front = rotate(player->plan_front, angle + to_radians(1), CLOCKWISE);
	player->plan_right = rotate(player->plan_right, angle + to_radians(1), CLOCKWISE);
	player->camera_angle = to_degrees(angle);
	rays_rotate(player->rays, angle + to_radians(1), CLOCKWISE);
	init_rays(player);
}

int		get_starting_point(t_game *data)
{
	t_vec i;
	char	visited;

	i = (typeof(i)){0, 0};
	visited = FALSE;
	while (i.y < data->map.map_ysize)
	{
		while (i.x < data->map.map_xsize)
		{
			if (is_cardinal_point(data->map.map[i.y][i.x]) && !visited)
			{
				set_heading(&data->camera, data->map.map[i.y][i.x]);
				data->camera.pos.x = (float)i.x + 0.5;
				data->camera.pos.y = (float)i.y + 0.5;
				visited = TRUE;
			}
			else if (is_cardinal_point(data->map.map[i.y][i.x]) && visited == TRUE)
				return (CODE_ERR_TOO_MANY_START_POINT);
			i.x++;
		}
		i.x = 0;
		i.y++;
	}
	return ((visited) ? FOUND : CODE_ERR_NO_START_PNT_PROVIDED);
}

void	render(t_game *data)
{
	draw_ceil_and_floor(data);
	raycasting(data);
	minimap(data);
	if (data->save)
	{
		printf("Resolution : %ix%i\n", data->map.resolution.x, data->map.resolution.y);
		export_to_bmp(SAVE_NAME, data);
		exit(0);
	}
}