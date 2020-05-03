/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony <tony@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 01:45:36 by bbellavi          #+#    #+#             */
/*   Updated: 2020/05/03 15:24:48 by tony             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser.h"
#include <stdio.h>
#include "render.h"
#include "colors.h"
#include "render.h"
#define WINDOW_NAME "cub3d"
#define WINDOW_HEIGHT 400
#define WINDOW_WIDTH 600
#define FIELD_OF_VIEW 90.0f
#define HEIGHT 10
#define WIDTH 10

void	define_map(t_map *map)
{
	static char *str_map[HEIGHT] = {
		"11111111111111",
		"10000100000001",
		"10E01100000001",
		"10000000000001",
		"10000000000001",
		"10000000000001",
		"11111111111111",
		NULL
	};

	map->map = str_map;
	map->ceil_color = COLOR_CEIL;
	map->ground_color = COLOR_FLOOR;
	map->map_xsize = 14;
	map->map_ysize = 7;
}

void	init_rays(t_camera *cam)
{
	const float		fov_mid = cam->field_of_view / 2;
	const float		step = FIELD_OF_VIEW / ((RAYS_NUMBER == 1) ? 1 : RAYS_NUMBER - 1);
	const t_vec2	dir = (t_vec2){1, 0};
	size_t			index;

	index = 0; 
	while (index < RAYS_NUMBER)
	{
		cam->rays[index].pos.x = 0;
		cam->rays[index].pos.y = 0;
		cam->rays[index].particle.x = 0;
		cam->rays[index].particle.y = 0;
		cam->rays[index].dir = dir;
		cam->rays[index].angle = 0;
		Ray_rotate(&cam->rays[index], to_radians(step * index), CLOCKWISE);
		index++;
	}
	if (RAYS_NUMBER != 1)
		Rays_rotate(cam->rays, to_radians(fov_mid), ANTI_CLOCKWISE);
}

void	init_game(t_game *data)
{
	data->map.resolution.x = WINDOW_WIDTH;
	data->map.resolution.y = WINDOW_HEIGHT;
	data->infos.mlx_ptr = mlx_init();
	data->infos.win_ptr = mlx_new_window(
		data->infos.mlx_ptr,
		data->map.resolution.x,
		data->map.resolution.y,
		WINDOW_NAME
	);
	data->map.ceil_color = COLOR_CEIL;
	data->map.ground_color = COLOR_FLOOR;
	data->camera.pos.x = 5;
	data->camera.pos.y = 3;
	data->camera.field_of_view = FIELD_OF_VIEW;
	data->camera.debug = FALSE;
}

int		main(int argc, char __unused **argv)
{
	t_game data;
	
	if (argc > 1)
	{
		init_game(&data);
		define_map(&data.map);

		data.image.img_ref = mlx_new_image(
			data.infos.mlx_ptr,
			data.map.resolution.x,
			data.map.resolution.y);
		data.image.img_data_addr = (int*)mlx_get_data_addr(
			data.image.img_ref,
			&data.image.bits_per_pixel,
			&data.image.line_size,
			&data.image.endian);
		data.image.line_count = data.map.resolution.y;

		get_starting_point(&data);
		init_rays(&data.camera);

		mlx_hook(data.infos.win_ptr, KEY_PRESS_CODE, KEY_PRESS_MASK, key_pressed, &data);
		mlx_hook(data.infos.win_ptr, KEY_RELEASE_CODE, KEY_RELEASE_MASK, key_released, &data);

		mlx_loop_hook(data.infos.mlx_ptr, loop, &data);
		mlx_loop(data.infos.mlx_ptr);
	}
}