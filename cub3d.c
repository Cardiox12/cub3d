/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 01:45:36 by bbellavi          #+#    #+#             */
/*   Updated: 2020/05/18 21:26:34 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser.h"
#include <stdio.h>
#include "render.h"
#include "colors.h"
#include "render.h"
#define WINDOW_NAME "cub3d"
#define WINDOW_HEIGHT 600
#define WINDOW_WIDTH 1000
#define FIELD_OF_VIEW 66.0f
#define HEIGHT 10
#define WIDTH 10

void	define_map(t_map *map)
{
	static char *str_map[HEIGHT] = {
		"11111111111111",
		"10000002000001",
		"10003002000001",
		"10N00000040001",
		"10003002000001",
		"10000002000001",
		"11111111111111",
		NULL
	};

	map->map = str_map;
	map->ceil_color = COLOR_CEIL;
	map->ground_color = COLOR_FLOOR;
	map->map_xsize = 14;
	map->map_ysize = 7;
}

void	init_textures(t_game *data)
{
	t_texture *text = data->map.textures;

	text[0].path = "./assets/redbricks.xpm";
	text[1].path = "./assets/bluestone.xpm";
	text[2].path = "./assets/colorstone.xpm";
	text[3].path = "./assets/eagle.xpm";
	text[0].image.img_ref = mlx_xpm_file_to_image(data->infos.mlx_ptr, text[0].path, &text[0].width, &text[0].height);
	text[1].image.img_ref = mlx_xpm_file_to_image(data->infos.mlx_ptr, text[1].path, &text[1].width, &text[1].height);
	text[2].image.img_ref = mlx_xpm_file_to_image(data->infos.mlx_ptr, text[2].path, &text[2].width, &text[2].height);
	text[3].image.img_ref = mlx_xpm_file_to_image(data->infos.mlx_ptr, text[3].path, &text[3].width, &text[3].height);

	text[0].image.img_data_addr = (int*)mlx_get_data_addr(text[0].image.img_ref, &text[0].image.bits_per_pixel, &text[0].image.line_size, &text[0].image.endian);
	text[1].image.img_data_addr = (int*)mlx_get_data_addr(text[1].image.img_ref, &text[1].image.bits_per_pixel, &text[1].image.line_size, &text[1].image.endian);
	text[2].image.img_data_addr = (int*)mlx_get_data_addr(text[2].image.img_ref, &text[2].image.bits_per_pixel, &text[2].image.line_size, &text[2].image.endian);
	text[3].image.img_data_addr = (int*)mlx_get_data_addr(text[3].image.img_ref, &text[3].image.bits_per_pixel, &text[3].image.line_size, &text[3].image.endian);
	if (text[0].image.img_ref != NULL && text[1].image.img_ref && text[2].image.img_ref && text[3].image.img_ref)
	{
		printf("Sucessfuly loaded textures.\n");
		printf("\tImage : %s of dimensions %ix%i\n", text[0].path, text[0].width, text[0].height);
		printf("\tImage : %s of dimensions %ix%i\n", text[1].path, text[1].width, text[1].height);
		printf("\tImage : %s of dimensions %ix%i\n", text[2].path, text[2].width, text[2].height);
		printf("\tImage : %s of dimensions %ix%i\n", text[3].path, text[3].width, text[3].height);
	}
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

int		main(int argc, char **argv)
{
	t_game data;
	
	if (argc > 1)
	{
		const unsigned int ret = parse(&data, argv[1]);
	
		return (ret);
		// init_game(&data);
		// define_map(&data.map);
		// init_textures(&data);
		
		// data.image.img_ref = mlx_new_image(
		// 	data.infos.mlx_ptr,
		// 	data.map.resolution.x,
		// 	data.map.resolution.y);
		// data.image.img_data_addr = (int*)mlx_get_data_addr(
		// 	data.image.img_ref,
		// 	&data.image.bits_per_pixel,
		// 	&data.image.line_size,
		// 	&data.image.endian);
		// data.image.line_count = data.map.resolution.y;
		
		// get_starting_point(&data);
		
		// mlx_hook(data.infos.win_ptr, KEY_PRESS_CODE, KEY_PRESS_MASK, key_pressed, &data);
		// mlx_hook(data.infos.win_ptr, KEY_RELEASE_CODE, KEY_RELEASE_MASK, key_released, &data);

		// mlx_loop_hook(data.infos.mlx_ptr, loop, &data);
		// mlx_loop(data.infos.mlx_ptr);
	}
	return (0);
}
