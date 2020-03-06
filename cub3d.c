/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 01:45:36 by bbellavi          #+#    #+#             */
/*   Updated: 2020/03/06 14:25:57 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser.h"
#include <stdio.h>
#include "render.h"
#include "colors.h"
#define WINDOW_NAME "cub3d"
#define WINDOW_HEIGHT 720
#define WINDOW_WIDTH 1280
#define HEIGHT 10
#define WIDTH 10

void	define_map(t_map *map)
{
	static char *str_map[HEIGHT] = {
		"11111",
		"10001",
		"10S01",
		"10001",
		"11111",
		NULL
	};

	map->map = str_map;
	map->ceil_color = COLOR_CEIL;
	map->ground_color = COLOR_FLOOR;
	map->map_xsize = 5;
	map->map_ysize = 5;
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
}

int		main(int argc, char __unused **argv)
{
	t_game data;
	
	if (argc > 1)
	{
		init_game(&data);
		define_map(&data.map);
		// parse_map(argv[1], &data.map);
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

		mlx_key_hook(data.infos.win_ptr, keyboard_hook, &data);
		mlx_loop_hook(data.infos.mlx_ptr, loop, &data);
		mlx_loop(data.infos.mlx_ptr);
	}
}