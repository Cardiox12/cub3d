/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 01:45:36 by bbellavi          #+#    #+#             */
/*   Updated: 2020/05/25 06:00:06 by bbellavi         ###   ########.fr       */
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

void	init_textures(t_game *data)
{
	t_texture *text = data->map.textures;

	text[0].image.img_ref = mlx_xpm_file_to_image(data->infos.mlx_ptr, text[0].path, &text[0].width, &text[0].height);
	text[1].image.img_ref = mlx_xpm_file_to_image(data->infos.mlx_ptr, text[1].path, &text[1].width, &text[1].height);
	text[2].image.img_ref = mlx_xpm_file_to_image(data->infos.mlx_ptr, text[2].path, &text[2].width, &text[2].height);
	text[3].image.img_ref = mlx_xpm_file_to_image(data->infos.mlx_ptr, text[3].path, &text[3].width, &text[3].height);

	if (text[0].image.img_ref != NULL && text[1].image.img_ref && text[2].image.img_ref && text[3].image.img_ref)
	{
		// printf("Sucessfuly loaded textures.\n");
		// printf("\tImage : %s of dimensions %ix%i\n", text[0].path, text[0].width, text[0].height);
		// printf("\tImage : %s of dimensions %ix%i\n", text[1].path, text[1].width, text[1].height);
		// printf("\tImage : %s of dimensions %ix%i\n", text[2].path, text[2].width, text[2].height);
		// printf("\tImage : %s of dimensions %ix%i\n", text[3].path, text[3].width, text[3].height);
	}
	else
	{
		printf("Error with file.\n");
		exit(0);
	}

	text[0].image.img_data_addr = (int*)mlx_get_data_addr(text[0].image.img_ref, &text[0].image.bits_per_pixel, &text[0].image.line_size, &text[0].image.endian);
	text[1].image.img_data_addr = (int*)mlx_get_data_addr(text[1].image.img_ref, &text[1].image.bits_per_pixel, &text[1].image.line_size, &text[1].image.endian);
	text[2].image.img_data_addr = (int*)mlx_get_data_addr(text[2].image.img_ref, &text[2].image.bits_per_pixel, &text[2].image.line_size, &text[2].image.endian);
	text[3].image.img_data_addr = (int*)mlx_get_data_addr(text[3].image.img_ref, &text[3].image.bits_per_pixel, &text[3].image.line_size, &text[3].image.endian);
}

void	init_game(t_game *data)
{
	unsigned int minres;
	unsigned int minsize;

	minres = min(data->map.resolution.x, data->map.resolution.y);
	minsize = min(data->map.map_xsize, data->map.map_ysize);
	data->infos.mlx_ptr = mlx_init();
	data->infos.win_ptr = mlx_new_window(
		data->infos.mlx_ptr,
		data->map.resolution.x,
		data->map.resolution.y,
		WINDOW_NAME
	);
	data->camera.field_of_view = FIELD_OF_VIEW;
	data->camera.debug = FALSE;
	data->map.specs_number = 0;
	data->minimap.size = minres * ((float)MINIMAP_RATIO / 100);
	data->minimap.square_size = data->minimap.size / minsize;
}

void	Debug_log_game(t_game *data, const char *path)
{
	printf("Map path : %s\n", path);
	printf("================================ TEXTURES : ================================\n");
	printf("North texture : %s\n", data->map.textures[IDX_NORTH].path);
	printf("South texture : %s\n", data->map.textures[IDX_SOUTH].path);
	printf("West texture : %s\n", data->map.textures[IDX_WEST].path);
	printf("East texture : %s\n", data->map.textures[IDX_EAST].path);
	printf("Sprite texture : %s\n", data->map.textures[IDX_SPRITE].path);
	printf("================================ RESOLUTION : ================================\n");
	printf("Resolution : %ix%i\n", data->map.resolution.x, data->map.resolution.y);
	printf("================================ COULEURS : ================================\n");
	printf("Floor color : %x\n", data->map.floor_color);
	printf("Ceil color : %x\n", data->map.ceil_color);
	printf("================================ MAP : ================================\n");
	printf("Map height : %i\n", data->map.map_ysize);
	printf("Map width : %i\n", data->map.map_xsize);
	for (int i =  0 ; data->map.map[i] != NULL ; i++)
		printf("%s\n", data->map.map[i]);
}

int		main(int argc, char **argv)
{
	t_game data;
	
	if (argc > 1)
	{
		const int ret = parse(&data, argv[1]);
	
		if (ret)
		{
			exit(0);
		}
		// else
		// 	Debug_log_game(&data, argv[1]);
		
		// return (ret);
		// define_map(&data.map);
		init_game(&data);
		init_textures(&data);
		
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
		mlx_hook(data.infos.win_ptr, KEY_PRESS_CODE, KEY_PRESS_MASK, key_pressed, &data);
		mlx_hook(data.infos.win_ptr, KEY_RELEASE_CODE, KEY_RELEASE_MASK, key_released, &data);

		mlx_loop_hook(data.infos.mlx_ptr, loop, &data);
		mlx_loop(data.infos.mlx_ptr);
	}
	return (0);
}
