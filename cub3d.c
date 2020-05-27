/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 01:45:36 by bbellavi          #+#    #+#             */
/*   Updated: 2020/05/28 01:32:26 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser.h"
#include <stdio.h>
#include "render.h"
#include "colors.h"
#include "render.h"

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

	for (int i = 0 ; i < data->map.sprites.cursor ; i++)
	{
		printf("Sprite :\n");
		printf("\tPos : (%f, %f)\n", data->map.sprites.sprites[i].pos.x, data->map.sprites.sprites[i].pos.y);
	}
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

		init_game(&data);
		init_textures(&data);
		parse_sprites(&data);

		Debug_log_game(&data, argv[1]);
		data.camera.ZBuffer = malloc(sizeof(double) * data.map.resolution.x);
		data.camera.sprite_order = malloc(sizeof(int) * data.map.sprites.cursor);
		data.camera.sprite_distance = malloc(sizeof(double) * data.map.sprites.cursor);
		
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
